#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long, int>>> edges(n, vector<pair<long long, int>>());
    int u, v;
    long long w;
    vector<pair<pair<int, int>, long long>> E;
    vector<pair<long long, pair<int, int>>> E_;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--; v--;
        E.push_back({{u, v}, w});
        E_.push_back({w, {u, v}});
    }
    sort(E_.begin(), E_.end());
    dsu UF(n);
    long long tot = 0;
    for(auto tmp:E_){
        w = tmp.first;
        u = tmp.second.first;
        v = tmp.second.second;
        if(!UF.same(u, v)){
            UF.merge(u, v);
            tot += w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
    }
    int logn = 20;
    vector<int> depth(n, -1);
    vector<vector<int>> parent(logn, vector<int>(n, -1));
    vector<vector<long long>> weight(logn, vector<long long>(n, -1));
    stack<int> st;
    st.push(0);
    depth[0] = 0;
    while(!st.empty()){
        int pos = st.top();
        st.pop();
        for(auto tmp:edges[pos]){
            int npos = tmp.first;
            int w = tmp.second;
            if(depth[npos] != -1) continue;
            depth[npos] = depth[pos] + 1;
            parent[0][npos] = pos;
            weight[0][npos] = w;
            st.push(npos);
        }
    }
    for(int i = 1; i < logn; i++){
        for(int j = 0; j < n; j++){
            if(parent[i - 1][j] != -1){
                int p = parent[i - 1][j];
                parent[i][j] = parent[i - 1][p];
                weight[i][j] = max(weight[i - 1][j], weight[i - 1][p]);
            }
        }
    }
    auto get=[&](int u, int v) -> long long{
        if(depth[v] < depth[u]) swap(u, v);
        int du = depth[u];
        int dv = depth[v];
        long long ret = 0;
        for(int i = 0; i < logn; i++){
            if(((dv - du) >> i) & 1){
                ret = max(ret, weight[i][v]);
                v = parent[i][v];
            }
        }
        if(u == v) return ret;
        for(int i = logn - 1; i >= 0; i--){
            int pu = parent[i][u];
            int pv = parent[i][v];
            if(pu != pv){
                ret = max(ret, weight[i][u]);
                ret = max(ret, weight[i][v]);
                u = pu;
                v = pv;
            }
        }
        ret = max(ret, weight[0][u]);
        ret = max(ret, weight[0][v]);
        return ret;
    };
    for(auto tmp:E){
        u = tmp.first.first;
        v = tmp.first.second;
        w = tmp.second;
        long long ma = get(u, v);
        if(ma >= w) cout << tot << "\n";
        else cout << tot + w - ma << "\n";

    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) solve();
}