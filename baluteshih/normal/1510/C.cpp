#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define SZ(a) ((int)a.size())

vector<int> G[100005], nG[100005], BCC[100005], stk;
vector<pii> edges, ans;
int vis[100005];
int dfn[100005], low[100005], dft, bcc_cnt;

void dfs(int u, int pa = -1) {
    low[u] = dfn[u] = ++dft;
    for (int e : G[u]) {
        int v = edges[e].X ^ edges[e].Y ^ u;
        if (!dfn[v]) {
            stk.pb(e);
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                ++bcc_cnt;
                int t;
                do {
                    t = stk.back(), stk.pop_back();
                    BCC[bcc_cnt].pb(t);
                } while (t != e);
            }
        }
        else if (dfn[v] < dfn[u] && v != pa)
            low[u] = min(low[u], dfn[v]), stk.pb(e);
    }
}

int dfs2(int u, int f) {
    vis[u] = 1;
    vector<int> path, uni;
    for (int i : nG[u])
        if (i != f) {
            int rt = dfs2(i, u);
            if (rt == i)
                uni.pb(rt);
            else
                path.pb(rt);
        }
    if (u == f) {
        for (int i = 0; i + 1 < SZ(path); i += 2)
            ans.pb(pii(path[i], path[i + 1]));
        if (SZ(path) & 1) {
            if (uni.empty())
                ans.pb(pii(path.back(), u));
            else {
                ans.pb(pii(path.back(), uni[0]));
                for (int i = 1; i + 1 < SZ(uni); i += 2)
                    ans.pb(pii(uni[i], uni[i + 1]));
            }
        }
        else {
            for (int i = 0; i + 1 < SZ(uni); i += 2)
                ans.pb(pii(uni[i], uni[i + 1]));
        }
        return 0;
    }
    if (path.empty() && uni.empty())
        return u;
    for (int i = 0; i + 1 < SZ(path); i += 2)
        ans.pb(pii(path[i], path[i + 1]));
    if (SZ(path) & 1) {
        if (SZ(uni) <= 1)
            return path.back();
        ans.pb(pii(path.back(), uni[0]));
        if (SZ(uni) & 1) {
            for (int i = 1; i + 2 < SZ(uni); i += 2)
                ans.pb(pii(uni[i], uni[i + 1]));
            return uni.back();
        }
        else {
            for (int i = 1; i + 1 < SZ(uni); i += 2)
                ans.pb(pii(uni[i], uni[i + 1]));
            return uni.back();
        }
    }
    else {
        if (SZ(uni) & 1) {
            for (int i = 0; i + 1 < SZ(uni); i += 2)
                ans.pb(pii(uni[i], uni[i + 1]));
            return uni.back();
        }
        else {
            if (uni.empty())
                return u;
            for (int i = 0; i + 2 < SZ(uni); i += 2)
                ans.pb(pii(uni[i], uni[i + 1]));
            return uni.back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    while (cin >> n >> m && n + m) {
        for (int i = 1; i <= n; ++i)
            G[i].clear(), nG[i].clear(), BCC[i].clear(), dfn[i] = low[i] = vis[i] = 0;
        edges.clear(), dft = 0, bcc_cnt = 0;
        while (m--) {
            int k;
            cin >> k;
            int lst = 0;
            for (int i = 1; i <= k; ++i) {
                int x;
                cin >> x;
                if (i > 1) {
                    G[x].pb(SZ(edges)), G[lst].pb(SZ(edges));
                    edges.pb(pii(x, lst));
                }
                lst = x;
            }
        }
        for (int i = 1; i <= n; ++i)
            if (!dfn[i])
                dfs(i);
        for (int i = 1; i <= bcc_cnt; ++i)
            if (SZ(BCC[i]) == 1) {
                pii e = edges[BCC[i][0]];
                nG[e.X].pb(e.Y), nG[e.Y].pb(e.X);
            }
        ans.clear();
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                dfs2(i, i);
        cout << SZ(ans) << "\n";
        for (pii e : ans)
            cout << e.X << " " << e.Y << "\n";
    }
}