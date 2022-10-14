#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef pair<int, int> pi;
struct edge {
    int x, y, w, id;
};
vector<edge> e;
vector<int> rt, dep;
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
int main() {
    int n, m;
    cin >> n >> m;
    rt.resize(n), iota(rt.begin(), rt.end(), 0), e.resize(m), g.resize(n);
    for (edge &i : e) cin >> i.x >> i.y >> i.w, --i.x, --i.y;
    for (int i = 0; i < m; ++i) e[i].id = i;
    vector<edge> q;
    sort(e.begin(), e.end(), [](edge i, edge j){return i.w < j.w;});
    for (edge i : e) {
        int x = find(i.x), y = find(i.y);
        if (x != y) {
            rt[x] = y;
            g[i.x].emplace_back(i.y, i.w);
            g[i.y].emplace_back(i.x, i.w);
        }
        else q.push_back(i);
    }
    pa.assign(n, vector<int>(20, 0));
    dis.assign(n, vector<int>(20, 0));
    dep.assign(n, 0);
    dfs(0, 0), build();
    sort(q.begin(), q.end(), [](edge i, edge j){return i.id < j.id;});
    for (edge i : q) cout << query(i.x, i.y) << '\n';
}