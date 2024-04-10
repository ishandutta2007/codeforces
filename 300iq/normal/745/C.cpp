#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e3 + 1;
vector <int> g[N];
int cnt = 0;
int comp[N];
int tt = 0;
bool c[N];
bool u[N];
bool t[N][N];
int sum = 0;

void dfs(int v)
{
    sum++;
    comp[v] = tt;
    u[v] = 1;
    cnt += c[v];
    for (auto to: g[v])
    {
        if (!u[to])
        {
            dfs(to);
        }
    }
}



int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int v;
        cin >> v;
        c[v] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        t[u][v] = t[v][u] = 1;
    }
    int a = 0, b = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!u[i])
        {
            tt++;
            sum = 0;
            cnt = 0;
            dfs(i);
            if (cnt)
            {
                a = max(a, sum);
            }
            else
            {
                ans += b * sum;
                b += sum;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (comp[i] == comp[j] && !t[i][j])
            {
                ans++;
                t[i][j] = t[j][i] = 1;
            }
        }
    }
    cout << ans + a * b << '\n';
}