#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef pair<int, int> pi;
struct edge {
    int x, y, w, id;
};
int _id = 0;
vector<edge> e;
vector<int> rt, dep, sz, hd, pc, id;
vector<vector<pi>> g;
vector<vector<int>> pa, dis;
int find(int i) {
    if (i == rt[i]) return i;
    return rt[i] = find(rt[i]);
}
void dfs(int i, int p) {
    for (pi j : g[i]) if (j.first != p) {
        pa[j.first][0] = i, dis[j.first][0] = j.second, dep[j.first] = dep[i] + 1;
        dfs(j.first, i);
        sz[i] += sz[j.first];
        if (pc[i] == -1 || sz[pc[i]] < sz[j.first]) pc[i] = j.first;
    }
}
void build() {
    for (int i = 1; i < 20; ++i) for (int j = 0; j < pa.size(); ++j) {
        pa[j][i] = pa[pa[j][i - 1]][i - 1];
        dis[j][i] = max(dis[j][i - 1], dis[pa[j][i - 1]][i - 1]);
    }
}
int query(int i, int j) {
    int ans = 0;
    if (dep[i] < dep[j]) swap(i, j);
    for (int ii = 19; ~ii; --ii) if (dep[pa[i][ii]] >= dep[j]) {
        ans = max(ans, dis[i][ii]);
        i = pa[i][ii];
    }
    for (int ii = 19; ~ii; --ii) if (pa[i][ii] != pa[j][ii]) {
        ans = max({ans, dis[i][ii], dis[j][ii]});
        i = pa[i][ii], j = pa[j][ii];
    }
    if (i != j) ans = max({ans, dis[i][0], dis[j][0]});
    return ans;
}
void hld(int i, int p, int h) {
    if (i == -1) return;
    id[i] = _id++, hd[i] = h;
    hld(pc[i], i, h);
    for (pi j : g[i]) if (j.first != p && j.first != pc[i])
        hld(j.first, i, j.first);
}
struct seg {
    int l, r, v = 1e9;
    seg *ch[2]{};
    seg() = default;
    seg (int _l, int _r) : l(_l), r(_r) {
        if (l < r - 1) ch[0] = new seg(l, l + r >> 1), ch[1] = new seg(l + r >> 1, r);
    }
    void modify(int _l, int _r, int d) {
        if (_l <= l && r <= _r) {
            v = min(v, d);
            return;
        }
        int m = l + r >> 1;
        if (_l < m) ch[0]->modify(_l, _r, d);
        if (m < _r) ch[1]->modify(_l, _r, d);
    }
    int query(int i) {
        if (l == r - 1) return v;
        return min(v, ch[i >= l + r >> 1]->query(i));
    }
} sg;
void add(edge ei) {
    int i = ei.x, j = ei.y, d = ei.w;
    while (hd[i] != hd[j]) {
        if (dep[hd[i]] >= dep[hd[j]]) {
            sg.modify(id[hd[i]], id[i] + 1, d);
            i = pa[hd[i]][0];
        }
        else {
            sg.modify(id[hd[j]], id[j] + 1, d);
            j = pa[hd[j]][0];
        }
    }
    sg.modify(min(id[i], id[j]) + 1, max(id[i], id[j]) + 1, d);
}
int main() {
    int n, m;
    cin >> n >> m;
    sg = seg(0, n);
    rt.resize(n), iota(rt.begin(), rt.end(), 0), e.resize(m), g.resize(n);
    for (edge &i : e) cin >> i.x >> i.y >> i.w, --i.x, --i.y;
    for (int i = 0; i < m; ++i) e[i].id = i;
    vector<edge> q, q2;
    sort(e.begin(), e.end(), [](edge i, edge j){return i.w < j.w;});
    for (edge i : e) {
        int x = find(i.x), y = find(i.y);
        if (x != y) {
            rt[x] = y;
            g[i.x].emplace_back(i.y, i.w);
            g[i.y].emplace_back(i.x, i.w);
            q2.push_back(i);
        }
        else q.push_back(i);
    }
    pa.assign(n, vector<int>(20, 0));
    dis.assign(n, vector<int>(20, 0));
    dep.assign(n, 0), sz.assign(n, 1), pc.assign(n, -1), hd.resize(n), id.resize(n);
    dfs(0, 0), build(), hld(0, 0, 0);
    int ans[m];
    for (edge i : q) {
        ans[i.id] = query(i.x, i.y);
        add(i);
    }
    for (edge i : q2) {
        ans[i.id] = sg.query(id[dep[i.x] > dep[i.y] ? i.x : i.y]);
    }
    for (int i : ans) cout << i << '\n';
}