#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 19;

int n, m;
bool a[N][N];

int q[(1 << N)];
vector<int> v[N];

long long dp[(1 << N)][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        a[x][y] = a[y][x] = true;
    }
    for (int x = 1; x < (1 << n); ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                v[i].push_back(x);
                break;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                ++q[x];
        }
    }
    long long ans = 0;
    for (int s = 0; s < n; ++s)
    {
        dp[(1 << s)][s] = 1;
        for (int ii = 0; ii < v[s].size(); ++ii)
        {
            int x = v[s][ii];
            for (int i = s; i < n; ++i)
            {
                if (a[s][i] && q[x] > 2)
                    ans += dp[x][i];
                if (!(x & (1 << i)))
                    continue;
                for (int j = s; j < n; ++j)
                {
                    if ((x & (1 << j)))
                        continue;
                    if (a[i][j])
                        dp[(x | (1 << j))][j] += dp[x][i];
                }
            }
        }
    }
    printf("%lld\n", ans / 2);
    return 0;
}