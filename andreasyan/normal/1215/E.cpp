#include <bits/stdc++.h>
using namespace std;
const int N = 400005, m = 20;

int n;
int a[N];

vector<int> v[m];
long long q[m][m];

long long dp[1 << m];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        --a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        v[a[i]].push_back(i);
    }
    for (int x = 0; x < m; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            if (x == y)
                continue;
            int j = -1;
            for (int i = 0; i < v[x].size(); ++i)
            {
                while (j + 1 < v[y].size() && v[y][j + 1] < v[x][i])
                    ++j;
                q[x][y] += (j + 1);
            }
        }
    }
    for (int x = 1; x < (1 << m); ++x)
        dp[x] = (N * 1LL * N);
    for (int x = 0; x < (1 << m); ++x)
    {
        for (int i = 0; i < m; ++i)
        {
            if (!(x & (1 << i)))
            {
                int y = (x | (1 << i));
                long long p = 0;
                for (int j = 0; j < m; ++j)
                {
                    if (!(y & (1 << j)))
                        p += q[i][j];
                }
                dp[y] = min(dp[y], dp[x] + p);
            }
        }
    }
    cout << dp[(1 << m) - 1] << endl;
    return 0;
}