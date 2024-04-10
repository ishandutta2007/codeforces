#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 10;
vector<pii> G[N];
vi G2[N];
pii E[N];
int n, tp[N];
bool check;

void dfs(int u, int pid)
{
    vi vt[2];
    for (pii e : G[u])
        if (e.se != pid)
        {
            dfs(e.fi, e.se);
            vt[tp[e.se]].eb(e.se);
        }
    if (u != 1)
    {
        if (vt[0].size() > vt[1].size() + 2)
        {
            check = false;
            return;
        }
        if (vt[1].size() > vt[0].size() + 1)
        {
            check = false;
            return;
        }
        int par = 0, prv = 0;
        while (!vt[par].empty())
        {
            G2[prv].eb(vt[par].back());
            prv = vt[par].back();
            vt[par].pop_back();
            par ^= 1;
        }
        tp[pid] = par;
        vt[par].eb(pid);
        while (!vt[par].empty())
        {
            G2[prv].eb(vt[par].back());
            prv = vt[par].back();
            vt[par].pop_back();
            par ^= 1;
        }
    }
    else
    {
        if (vt[0].size() > vt[1].size() + 1)
        {
            check = false;
            return;
        }
        if (vt[1].size() > vt[0].size())
        {
            check = false;
            return;
        }
        int par = 0, prv = 0;
        while (!vt[par].empty())
        {
            G2[prv].eb(vt[par].back());
            prv = vt[par].back();
            vt[par].pop_back();
            par ^= 1;
        }
    }
}

int vis[N];
vector<pii> ans;

void dfs2(int u)
{
    vis[u] = 1;
    for (int v : G2[u])
        if (!vis[v]) dfs2(v);
        else if (vis[v] == 1)
        {
            check = false;
            return;
        }
    vis[u] = 2;
    ans.eb(E[u]);
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) G[i].clear(), G2[i].clear();
        for (int i = 1, u, v; i < n; ++i)
        {
            cin >> u >> v;
            G[u].eb(v, i);
            G[v].eb(u, i);
            E[i] = mp(u, v);
        }
        check = true;
        dfs(1, 0);
        for (int i = 1; i < n; ++i) vis[i] = 0;
        ans.clear();
        for (int i = 1; i < n; ++i)
            if (!vis[i]) dfs2(i);
        if (!check)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (pii pa : ans) cout << pa.fi << " " << pa.se << "\n";
    }
    return 0;
}