#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 500 + 1;
const int IT = 63;
bool vis[N][N];
bool gin[N][N][2][IT];
bool got[N][N][2][IT];
bitset <N> win[N][2][IT];
bitset <N> wout[N][2][IT];
ll mx[N][2][IT];
vector <pair <int, int> > g[N];

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].push_back({v, t});
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : g[i])
        {
            int to = x.first;
            int len = x.second;
            gin[i][to][len][0] = 1;
            got[to][i][len][0] = 1;
            win[i][len][0][to] = 1;
            wout[to][len][0][i] = 1;
            mx[i][len][1] = 1;
        }
    }
    for (int it = 0; it < IT; it++)
    {
        for (int i = 1; i <= n; i++)
        {
            mx[i][0][it + 1] = max(mx[i][0][it + 1], mx[i][0][it]);
            mx[i][1][it + 1] = max(mx[i][1][it + 1], mx[i][1][it]);
            for (int a = 1; a <= n; a++)
            {
                if (gin[a][i][0][it])
                {
                    mx[a][0][it + 1] = max(mx[a][0][it + 1], (1ll << it) + mx[i][1][it]);
                }
            }
            for (int a = 1; a <= n; a++)
            {
                if (gin[a][i][1][it])
                {
                    mx[a][1][it + 1] = max(mx[a][1][it + 1], (1ll << it) + mx[i][0][it]);
                }
            }
        }
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                if ((win[a][0][it] & wout[b][1][it]).count())
                {
                    win[a][0][it + 1][b] = 1;
                    wout[b][0][it + 1][a] = 1;
                    gin[a][b][0][it + 1] = 1;
                    got[b][a][0][it + 1] = 1;
                }
                if ((win[a][1][it] & wout[b][0][it]).count())
                {
                    win[a][1][it + 1][b] = 1;
                    wout[b][1][it + 1][a] = 1;
                    gin[a][b][1][it + 1] = 1;
                    got[b][a][1][it + 1] = 1;
                }
            }
        }
    }
    ll ans = 0;
    for (int it = 0; it < IT; it++)
    {
        ans = max(ans, mx[1][0][it]);
    }
    if (ans > (ll) 1e18)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
}