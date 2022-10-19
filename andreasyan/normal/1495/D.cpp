#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 402;
const int M = 998244353;

int n, m;
vector<int> g[N];

int d[N][N];

void bfs(int s, int d[])
{
    for (int x = 1; x <= n; ++x)
        d[x] = N;
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (d[h] == N)
            {
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
}

int r[N];

vector<int> gg[N];

vector<int> v[N];
int dp[N];
int q[N];
int p[N], s[N];

int ans[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int x = 1; x <= n; ++x)
    {
        bfs(x, d[x]);
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int z = 1; z <= n; ++z)
            gg[z].clear();
        for (int z = 1; z <= n; ++z)
        {
            for (int i = 0; i < g[z].size(); ++i)
            {
                int h = g[z][i];
                if (d[z][x] == d[h][x] + 1)
                    gg[z].push_back(h);
            }
        }
        for (int i = 0; i < n; ++i)
            v[i].clear();
        for (int y = 1; y <= n; ++y)
            v[d[x][y]].push_back(y);
        for (int y = x; y <= n; ++y)
        {
            memset(dp, 0, sizeof dp);
            dp[x] = 1;
            memset(q, 0, sizeof q);
            for (int i = 0; i < n; ++i)
            {
                if (v[i].empty())
                    break;
                for (int j = 0; j < v[i].size(); ++j)
                {
                    int z = v[i][j];
                    for (int k = 0; k < gg[z].size(); ++k)
                    {
                        int h = gg[z][k];
                        if (d[z][y] == 1 + d[h][y])
                        {
                            ++q[z];
                        }
                    }
                }
                p[0] = q[v[i][0]];
                for (int j = 1; j < v[i].size(); ++j)
                    p[j] = (p[j - 1] * 1LL * q[v[i][j]]) % M;
                s[sz(v[i]) - 1] = q[v[i][sz(v[i]) - 1]];
                for (int j = sz(v[i]) - 2; j >= 0; --j)
                    s[j] = (s[j + 1] * 1LL * q[v[i][j]]) % M;
                if (i <= d[x][y])
                {
                    for (int j = 0; j < v[i].size(); ++j)
                    {
                        int z = v[i][j];
                        int u = 1;
                        if (j > 0)
                            u = (u * 1LL * p[j - 1]) % M;
                        if (j < sz(v[i]) - 1)
                            u = (u * 1LL * s[j + 1]) % M;
                        for (int k = 0; k < gg[z].size(); ++k)
                        {
                            int h = gg[z][k];
                            if (d[z][y] + 1 == d[h][y])
                            {
                                dp[z] = (dp[z] + dp[h] * 1LL * u) % M;
                            }
                        }
                    }
                }
                else
                {
                    dp[y] = (dp[y] * 1LL * s[0]) % M;
                }
            }
            ans[y][x] = ans[x][y] = dp[y];
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            printf("%d ", ans[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}