#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int cmp[maxn], ans[2 * maxn], psh[(1 << 19)], sz[maxn];
set < pair < int, int > > in[maxn];
vector < pair < int, int > > open[maxn], ask[maxn];

void build(int i, int l, int r) {
    psh[i] = 2 * maxn;
    if (r - l == 1) return;
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
}

void update(int i, int l, int r, int lq, int rq, int x) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] = min(psh[i], x);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
}

int get(int i, int l, int r, int lq) {
    if (r - l == 1) return psh[i];
    int m = (r + l) / 2;
    if (lq < m) return min(get(2 * i + 1, l, m, lq), psh[i]);
    return min(psh[i], get(2 * i + 2, m, r, lq));
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, q, u, v, l, r;
    cin >> t;
    while (t--) {
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++) {
            cmp[i] = i, in[i] = {{i, i}}, open[i] = {}, ask[i] = {}, sz[i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            u = cmp[u], v = cmp[v];
            if (u == v) continue;
            if (sz[u] > sz[v]) swap(u, v);
            sz[v] += sz[u];
            for (auto key : in[u]) {
                for (int pos = key.first; pos <= key.second; pos++) cmp[pos] = v;
            }
            while ((int)in[u].size() > 0) {
                auto [L, R] = (*in[u].begin());
                in[u].erase(in[u].begin());
                auto it = in[v].lower_bound({L + 1, -1});
                if (it != in[v].begin()) {
                    it--;
                    if ((*it).second + 1 == L) {
                        L = (*it).first;
                        in[v].erase(it);
                    }
                }
                bool find = true;
                while (find) {
                    find = false;
                    it = in[v].lower_bound({R, -1});
                    if (it != in[v].end() && (*it).first == R + 1) {
                        R = (*it).second;
                        find = true;
                        in[v].erase(it);
                    }
                    it = in[u].lower_bound({R, -1});
                    if (it != in[u].end() && (*it).first == R + 1) {
                        R = (*it).second;
                        find = true;
                        in[u].erase(it);
                    }
                }
                in[v].insert({L, R});
                open[L].push_back({R, i});
            }
        }
        for (int i = 1; i <= q; i++) {
            cin >> l >> r;
            if (l == r) ans[i] = 0;
            else ask[l].push_back({r, i});
        }
        build(0, 1, n + 1);
        for (int i = 1; i <= n; i++) {
            for (auto key : open[i]) update(0, 1, n + 1, i, key.first + 1, key.second);
            for (auto key : ask[i]) ans[key.second] = get(0, 1, n + 1, key.first);
        }
        for (int i = 1; i <= q; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}