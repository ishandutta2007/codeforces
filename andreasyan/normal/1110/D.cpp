#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, m;
int a[N];

map<int, map<int, int> > dp[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    dp[1][a[1]][a[2]] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (map<int, map<int, int> >::iterator it1 = dp[i].begin(); it1 != dp[i].end(); ++it1)
        {
            int j = it1->first;
            for (map<int, int>::iterator it2 = dp[i][j].begin(); it2 != dp[i][j].end(); ++it2)
            {
                int k = it2->first;
                for (int pp = 0; pp <= min(min(min(j, k), a[i + 2]), 2); ++pp)
                {
                    dp[i + 1][k - pp][a[i + 2] - pp] = max(dp[i + 1][k - pp][a[i + 2] - pp], dp[i][j][k] + pp + (j - pp) / 3);
                }
            }
        }
    }
    cout << dp[m + 1][0][0] << endl;
    return 0;
}