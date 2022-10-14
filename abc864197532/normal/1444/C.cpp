#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

struct Dsu {
    struct cha {
        int x, dx, y, szy;
    };
    int n, cc;
    vector <int> dsu, size;
    vector <cha> stk;
    vector <int> point;
    Dsu (int _n): n(_n) {
        dsu.resize(n);
        size.resize(n);
        cc = n;
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int a) {
        if (dsu[a] == a) return a;
        return Find(dsu[a]);
    }
    bool Union(int a, int b) {
        int x = Find(a), y = Find(b);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        stk.push_back({x, dsu[x], y, size[y]});
        dsu[x] = y;
        size[y] += size[x];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
    void addPoint() {
        point.push_back(stk.size());
    }
    void rollback() {
        while (stk.size() > point.back()) {
            cha A = stk.back(); stk.pop_back();
            dsu[A.x] = A.dx;
            size[A.y] = A.szy;
            cc++;
        }
        point.pop_back();
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, u, v, _id = 0;
    cin >> n >> m >> k;
    vector<int> group(n);
    for (int i = 0; i < n; ++i) cin >> group[i], group[i]--;
    Dsu dsu(2 * n);
    vector<pair<int, int>> edge;
    map<pair<int, int>, int> m1;
    set<int> not_bia;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v, u--, v--;
        if (group[u] == group[v]) {
            if (dsu.same(u, v)) {
                not_bia.insert(group[u]);
            }
            dsu.Union(u, v + n);
            dsu.Union(v, u + n);
        } else {
            if (group[u] > group[v]) swap(u, v);
            edge.emplace_back(u, v);
            if (!m1.count({group[u], group[v]})) {
                m1[{group[u], group[v]}] = _id++;
            }
        }
    }
    vector<pair<int, int>> block[_id];
    while (edge.size()) {
        tie(u, v) = edge.back();
        edge.pop_back();
        if (not_bia.count(group[u]) || not_bia.count(group[v])) continue;
        block[m1[{group[u], group[v]}]].emplace_back(u, v);
    }
    int all = k - int(not_bia.size());
    long long ans = 1ll * all * (all - 1) / 2;
    for (int i = 0 ; i < _id; ++i) {
        dsu.addPoint();
        for (pair <int, int> p : block[i]) {
            if (dsu.same(p.first, p.second)) {
                ans--;
                break;
            }
            dsu.Union(p.first, p.second + n);
            dsu.Union(p.second, p.first + n);
        }
        dsu.rollback();
    }
    cout << ans << endl;
}