#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

vector <int> adj[N];
int sz[N], dep[N], ans[N];

void dfs1(int v, int pa) {
    sz[v] = 1;
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

vector <int> cc;

void dfs2(int v, int pa, bool is) {
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    if (is) cc.pb(v);
    for (int u : adj[v]) if (u != pa) {
        dfs2(u, v, is);
    }
}

int dsu[N];

void init() {
    for (int i = 0; i < N; ++i) dsu[i] = i;
}

int Find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = Find(dsu[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;
    dsu[u] = v;
}

bool same(int u, int v) {
    return Find(u) == Find(v);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    init();
    bool is = true;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        if (same(u, v)) is = false;
        Union(u, v);
    }
    if (!is) {
        while (q--) cout << -1 << endl;
        return 0;
    }
    vector <int> rt;
    for (int i = 0; i < N; ++i) if (sz[i] == 0) {
        dfs1(i, -1);
        if (sz[i] > 1) rt.pb(i);
    }
    int M = rt.size();
    vector <int> dis[M], dia(M, 0);
    vector <vector <lli>> pre;
    vector <double> only(M);
    map <int, int> m1;
    vector <int> big;
    for (int t = 0; t < M; ++t) {
        m1[Find(rt[t])] = t;
        dfs2(rt[t], -1, true);
        pii mx = {0, -1};
        for (int i : cc) mx = max(mx, mp(dep[i], i));
        dfs2(mx.Y, -1, false);
        mx = {0, -1};
        for (int i : cc) {
            ans[i] = max(ans[i], dep[i]);
            mx = max(mx, mp(dep[i], i));
        }
        dfs2(mx.Y, -1, false);
        for (int i : cc) ans[i] = max(ans[i], dep[i]);
        for (int i : cc) dis[t].pb(ans[i]);
        sort(all(dis[t]));
        dia[t] = dis[t].back();
        pre.pb({0});
        for (int i : dis[t]) {
            pre.back().pb(pre.back().back() + i);
            only[t] += max(i + 1, dia[t]);
        }
        only[t] /= dis[t].size();
        if (cc.size() >= K) big.pb(t);
        cc.clear();
    }
    map <pii, double> tans;
    for (int ii : big) {
        for (int jj : big) if (ii ^ jj) {
            lli al = 0;
            int dia1 = max(dia[ii], dia[jj]);
            bool is = false;
            if (dis[ii].size() > dis[jj].size()) is = true, swap(ii, jj);
            if (tans.count({ii, jj})) continue;
            for (int i : dis[ii]) {
                int p = lower_bound(all(dis[jj]), dia1 - i - 1) - dis[jj].begin();
                al += 1ll * dia1 * p + 1ll * (i + 1) * (dis[jj].size() - p) + pre[jj].back() - pre[jj][p];
            }
            double curr = al;
            curr /= dis[ii].size();
            curr /= dis[jj].size();
            tans[{ii, jj}] = curr;
            if (is) swap(ii, jj);
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v, u--, v--;
        u = Find(u), v = Find(v);
        if (u == v) {
            cout << -1 << endl;
        } else if (m1.count(u) && m1.count(v)) {
            u = m1[u], v = m1[v];
            if (tans.count({u, v})) cout << fixed << setprecision(10) << tans[{u, v}] << endl;
            else if (tans.count({v, u})) cout << fixed << setprecision(10) << tans[{v, u}] << endl;
            else {
                lli al = 0;
                int ii = u, jj = v;
                int dia1 = max(dia[ii], dia[jj]);
                if (dis[ii].size() > dis[jj].size()) swap(ii, jj);
                for (int i : dis[ii]) {
                    int p = lower_bound(all(dis[jj]), dia1 - i - 1) - dis[jj].begin();
                    al += 1ll * dia1 * p + 1ll * (i + 1) * (dis[jj].size() - p) + pre[jj].back() - pre[jj][p];
                }
                double curr = al;
                curr /= dis[ii].size();
                curr /= dis[jj].size();
                cout << fixed << setprecision(10) << curr << endl;
            }
        } else if (m1.count(u)) {
            cout << fixed << setprecision(10) << only[m1[u]] << endl;
        } else if (m1.count(v)) {
            cout << fixed << setprecision(10) << only[m1[v]] << endl;
        } else {
            cout << 1 << endl;
        }
    }
}