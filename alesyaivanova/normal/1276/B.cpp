#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()

const int maxn = 2e5 + 9;
vector<int> g[maxn];
int n, m, a, b;
bool used[maxn];

pii dfs(int v, int u)
{
    used[v] = 1;
    pii ans(1, v == u);
    for (int to : g[v])
    {
        if (!used[to])
        {
            pii cur = dfs(to, u);
            ans.ff += cur.ff;
            ans.ss |= cur.ss;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m >> a >> b;
    a--; b--;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    int sz1 = 0, sz2 = 0;
    for (int i = 0; i < n; i++)
        used[i] = 0;
    used[a] = 1;
    for (int to : g[a])
    {
        if (!used[to])
        {
            pii cur = dfs(to, b);
//            cout << a << " " << to << "?\n";
            if (!cur.ss)
                sz1 += cur.ff;
        }
    }
    for (int i = 0; i < n; i++)
        used[i] = 0;
    used[b] = 1;
    for (int to : g[b])
    {
        if (!used[to])
        {
            pii cur = dfs(to, a);
            if (!cur.ss)
                sz2 += cur.ff;
        }
    }
    for (int i = 0; i < n; i++)
    {
        g[i].resize(0);
        g[i].shrink_to_fit();
    }
    cout << sz1 * sz2 << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
        solve();
}