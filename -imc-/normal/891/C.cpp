#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

struct Edge {
    int u, v, w;
    int index;
    bool request;
    
    bool operator<(const Edge& e) const {
        if (w != e.w)
            return w < e.w;
        
        if (request != e.request)
            return request > e.request;
        
        return index < e.index;
    }
};

struct dsu_t {
    vector<int> p;
    vector<pair<int, int>> rollback;
    
    dsu_t(int n): p(n) {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    
    int get(int v) {
        if (p[v] == v)
            return v;
        else {
            int x = get(p[v]);
            rollback.emplace_back(v, p[v]);
            p[v] = x;
            return x;
        }
    }
    
    bool unite(int u, int v) {
        u = get(u);
        v = get(v);
        
        if (u == v) return false;
        
        if (rand() % 2) swap(u, v);
        rollback.emplace_back(u, p[u]);
        p[u] = v;
        return true;
    }
    
    void do_rollback() {
        for (int i = rollback.size() - 1; i >= 0; i--)
            p[rollback[i].first] = rollback[i].second;
        rollback.clear();
    }
};

void solve(bool /*read*/) {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--; e.v--;
        e.index = i;
        e.request = false;
        edges.push_back(e);
    }
    
    int nq;
    cin >> nq;
    for (int i = 0; i < nq; i++) {
        int ne;
        cin >> ne;
        
        for (int j = 0; j < ne; j++) {
            int k;
            cin >> k;
            k--;
            
            Edge x = edges[k];
            x.request = true;
            x.index = i;
            edges.push_back(x);
        }
    }
    
    sort(all(edges));
    
    dsu_t dsu(n);
    
    vector<char> fail(nq, false);
    
    for (int l = 0; l < edges.size(); ) {
        int r = l - 1;
        while (r + 1 < edges.size() && edges[r + 1].w == edges[l].w) r++;
        
        int x = l;
        while (edges[x].request) x++;
        
        //printf("block of w %d..%d..%d\n", l, x, r);
        
        for (int i = l; i < x; i++) {
            if (!i || edges[i].index != edges[i - 1].index) {
                dsu.do_rollback();
                //printf("rollback!\n");
            }
            
            if (fail[edges[i].index]) continue;
            if (!dsu.unite(edges[i].u, edges[i].v)) {
                fail[edges[i].index] = true;
            }
            else {
                //printf("unite %d %d\n", edges[i].u + 1, edges[i].v + 1);
            }
        }
        
        for (int i = x; i <= r; i++)
            dsu.unite(edges[i].u, edges[i].v);
        dsu.rollback.clear();
        
        l = r + 1;
    }
    
    for (int i = 0; i < nq; i++)
        cout << (fail[i] ? "NO" : "YES") << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}