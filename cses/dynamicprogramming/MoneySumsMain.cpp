/*
You have n coins with certain values. Your task is to find all money sums you can create using these coins.
Input
The first input line has an integer n: the number of coins.
The next line has n integers x1,x2,…,xn: the values of the coins.
Output
First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.
Constraints
1≤n≤100
1≤xi≤1000
Example
Input:
4
4 2 5 2
Output:
9
2 4 5 6 7 8 9 11 13
SOLUTION
0/1 Knapsack problem
dp[i][j] = true if it is possible to make sum j using the first i coins, false otherwise.
Base case: if ith coin == j, then dp[i][j] = true
Recurring relation: dp[i][j] = dp[i - 1][j] or dp[i - 1][j - ith coin]
Either take the ith coin or not.
Time O(N^2X)
Space O(N^2X)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> xs)
{
    sort(xs.begin(), xs.end());
    int j_max = n * 1000;
    vector<vector<bool>> dp(n + 1, vector<bool>(j_max + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= j_max; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int remainder = j - xs[i - 1];
            if (remainder >= 0 && dp[i - 1][remainder])
            {
                dp[i][j] = true;
            }
        }
    }
    vector<int> res;
    for (int j = 1; j <= j_max; j++)
    {
        if (dp[n][j])
        {
            res.push_back(j);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    vector<int> res = solve(n, xs);
    cout << res.size() << "\n";
    for (int r : res)
    {
        cout << r << " ";
    }
    return 0;
}
