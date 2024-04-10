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
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 9;
vector<pii> g[MAXN];
int n;
int p[MAXN];
int ans[MAXN];
int h[MAXN];
int pt;

void find_sz(int v)
{
    h[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i].ss;
        find_sz(to);
        h[v] = max(h[v], h[to] + 1);
        g[v][i].ff = h[to];
    }
    sort(all(g[v]));
}

void dfs1(int v)
{
    cout << v << " ";
    for (pii to : g[v])
        dfs1(to.ss);
}

void dfs(int v)
{
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        pii to = g[v][i];
        if (i)
        {
            for (int e = 0; e < (int)g[v][i - 1].ff; e++)
            {
                ans[pt] = to.ss;
                pt++;
            }
        }
        dfs(to.ss);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        g[x].pb(0, i);
        p[i] = x;
    }
    find_sz(0);
    dfs1(0);
    dfs(0);
    cout << "\n" << pt << "\n";
    for (int i = 0; i < pt; i++)
        cout << ans[i] << " ";
}