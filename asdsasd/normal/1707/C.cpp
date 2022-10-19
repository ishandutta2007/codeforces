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
const int N = 200200;
const int inf = 1 << 30;

//https://ei1333.github.io/luzhiled/snippets/other/random-number-generator.html
struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    dsu UF(n);
    int u, v;
    vector<pair<int, int>> ee;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        if(!UF.same(u, v)){
            UF.merge(u, v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        else{
            ee.push_back({u, v});
        }
    }

    vector<vector<int>> parent(20, vector<int>(n, -1));
    vector<int> depth(n, -1);
    stack<int> st;
    st.push(0);
    depth[0] = 0;
    while(!st.empty()){
        int pos = st.top();
        st.pop();
        for(auto npos:edges[pos]){
            if(depth[npos] != -1) continue;
            depth[npos] = depth[pos] + 1;
            st.push(npos);
            parent[0][npos] = pos;
        }
    }
    for(int i = 1; i < 20; i++){
        for(int v = 0; v < n; v++){
            if(parent[i - 1][v] != -1){
                parent[i][v] = parent[i - 1][parent[i - 1][v]];
            }
        }
    }

    auto get=[&](int u, int v){
        if(depth[v] < depth[u]) swap(u, v);
        int du = depth[u];
        int dv = depth[v];
        for(int i = 0; i < 20; i++){
            if(((dv - du) >> i) & 1) v = parent[i][v];
        }
        if(u == v) return u;
        
        for(int i = 19; i >= 0; i--){
            int pu = parent[i][u];
            int pv = parent[i][v];
            if(pu != pv){
                u = pu;
                v = pv;
            }
        }
        return parent[0][u];
    };
    vector<long long> XOR(n, 0);
    RandomNumberGenerator rnd;
    for(auto tmp:ee){
        int u = tmp.first;
        int v = tmp.second;
        int y = rnd(1 << 30);
        int z = rnd(1 << 30);
        long long x = ((long long)(y) << 30) | (long long)z;

        if(depth[u] > depth[v]) swap(u, v);
        int p = get(u, v);
        if(p != u){
            XOR[0] ^= x;
            XOR[u] ^= x;
            XOR[v] ^= x;
        }
        else{
            XOR[v] ^= x;
            int d = depth[v] - depth[u] - 1;
            int i = 0;
            while(d > 0){
                if(d & 1) v = parent[i][v];
                i++;
                d >>= 1;
            }
            XOR[v] ^= x;
        }
    }
    vector<char> ans(n);
    st.push(0);
    vector<bool> used(n, false);
    used[0] = true;
    while(!st.empty()){
        int pos = st.top();
        st.pop();
        if(XOR[pos] == 0) ans[pos] = '1';
        else ans[pos] = '0';
        for(auto npos:edges[pos]){
            if(used[npos]) continue;
            used[npos] = true;
            XOR[npos] ^= XOR[pos];
            st.push(npos);
        }
    }
    for(auto s:ans) cout << s;
    cout << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) solve();
}