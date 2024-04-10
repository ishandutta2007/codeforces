//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 1e5+10, inf = 1000111222;

const int max_lev=18;

class tree {
public:
    int tin[max_n], tout[max_n];
    int h[max_n]; // h[root] = 0
    int p[max_lev][max_n];

    void init(int n, vector<int> g[], int root = 0) {
        curt = -1;
        for (int i = 0; i < max_lev; ++i) {
            p[i][root] = root;
        }
        dfs(root, g);
        get_all_p(n);
    }

    bool is_ancestor(int u, int v) const {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    bool is_on_path(int u,int v,int lca,int q)
    {
        return is_ancestor(lca,q) && (is_ancestor(q,u) || is_ancestor(q,v));
    }

    bool is_edge_on_path(int u,int v,int lca,int q1,int q2)
    {
        return is_on_path(u,v,lca,q1) && is_on_path(u,v,lca,q2);
    }

    int lca(int u, int v) const {
        if (is_ancestor(u, v)) {
            return u;
        }
        for (int i = max_lev - 1; i >= 0; --i) {
            if (!is_ancestor(p[i][u], v)) {
                u = p[i][u];
            }
        }
        return p[0][u];
    }

    int get_dist(int u, int v) const {
        const int lc = lca(u, v);
        return h[u] + h[v] - 2 * h[lc];
    }

    int get_up(int v, int dist) const {
        for (int i = max_lev - 1; i >= 0; --i) {
            if (get_bit(dist, i)) {
                v = p[i][v];
            }
        }
        return v;
    }

protected:
    void dfs(int v, vector<int> g[]) {
        tin[v] = ++curt;
        for (int to : g[v]) {
            if (to == p[0][v]) {
                continue;
            }
            p[0][to] = v;
            h[to] = h[v] + 1;
            dfs(to, g);
        }
        tout[v] = curt;
    }

    void get_all_p(int n) {
        for (int lev = 1; lev < max_lev; ++lev) {
            for (int i = 0; i < n; ++i) {
                p[lev][i] = p[lev - 1][p[lev - 1][i]];
            }
        }
    }

    static bool get_bit(int mask, int pos) {
        return (mask >> pos) & 1;
    }

    int curt;
};

class heavy_light_tree : public tree {
public:
    int up[max_n], sz[max_n];
    vector<int> order;

    void init(int n, vector<int> g[], int root = 0) {
        curt = -1;
        for (int i = 0; i < max_lev; ++i) {
            p[i][root] = root;
        }
        reorder_subtrees(root, -1, g);
        up[root] = root;
        dfs(root, g);
        get_all_p(n);
    }

    template<bool lca_inclusive, typename Callback>
    void decompose_on_paths(int v1, int v2, Callback &callback) const {
        const int lc = lca(v1, v2);
        vertical_decompose_on_paths<lca_inclusive>(v1, lc, callback);
        vertical_decompose_on_paths<false>(v2, lc, callback);
    }

    template<bool lca_inclusive>
    vector<pair<int, int>> decompose_on_paths(int v1, int v2) const {
        vector<pair<int, int>> res;
        auto callback = [&res](int l, int r) { res.emplace_back(l, r); };
        decompose_on_paths<lca_inclusive>(v1, v2, callback);
        return res;
    }

    vector<int> get_light_edges_down(int u,int v,int lca) const {
        vector<int> res;
        lol_kek(u,lca,res);
        lol_kek(v,lca,res);
        return res;
    }

    void lol_kek(int v,int parent, vector<int>& res) const {
        while (true) {
            if (is_ancestor(up[v], parent)) {
                return;
            }
            res.pb(up[v]);
            v = p[0][up[v]];
        }
    }

private:
    template<bool parent_inclusive, typename Callback>
    void vertical_decompose_on_paths(int v, int parent, Callback &callback) const {
        while (true) {
            if (is_ancestor(up[v], parent)) {
                const int l = tin[parent] + !parent_inclusive, r = tin[v];
                if (l <= r) {
                    callback(l, r);
                }
                return;
            }
            callback(tin[up[v]], tin[v]);
            v = p[0][up[v]];
        }
    }

    void reorder_subtrees(int v, int p, vector<int> g[]) {
        sz[v] = 1;
        for (int i = 0; i < g[v].size(); ++i) {
            if (g[v][i] == p) {
                swap(g[v][i], g[v].back());
                g[v].pop_back();
                break;
            }
        }
        for (int to : g[v]) {
            reorder_subtrees(to, v, g);
            sz[v] += sz[to];
        }
        for (int i = 1; i < g[v].size(); ++i) {
            if (sz[g[v][i]] > sz[g[v][0]]) {
                swap(g[v][i], g[v][0]);
            }
        }
    }

    void dfs(int v, vector<int> g[]) {
        order.push_back(v);
        tin[v] = ++curt;
        sz[v] = 1;
        for (int to : g[v]) {
            if (to == p[0][v]) {
                continue;
            }
            up[to] = to;
            if (to == g[v][0]) {
                up[to] = up[v];
            }
            p[0][to] = v;
            h[to] = h[v] + 1;
            dfs(to, g);
            sz[v] += sz[to];
        }
        tout[v] = curt;
    }
};

vector<int> reb[max_n];

int a[max_n];

heavy_light_tree T;

const int magic=600;

int type[max_n];
int A[max_n];
int B[max_n];

ll pref_value[max_n];

void dfs_push_value(int now)
{
    for (auto wh:reb[now]){
        pref_value[wh]+=pref_value[now];
        dfs_push_value(wh);
    }
}

bool mark[max_n];

pair<bool,int> G[max_n];
int G_T;

bool get_G(int a)
{
    if (G[a].sec<G_T){
        G[a].fir=0;
        G[a].sec=G_T;
    }
    return G[a].fir;
}

void set_G(int a,bool val)
{
    if (G[a].sec<G_T){
        G[a].fir=0;
        G[a].sec=G_T;
    }
    G[a].fir=val;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;
        v--;

        reb[u].pb(v);
        reb[v].pb(u);
    }
    T.init(n,reb,0);

    for (int i=0;i<q;i++){
        scanf("%d%d%d",&type[i],&A[i],&B[i]);
        if (type[i]==1){
            A[i]--;
        }
        else{
            A[i]--;
            B[i]--;
        }
    }

    auto get_edge_w=[&](int a,int b)
    {
        return max(abs(a+b),abs(a-b));
    };

    for (int i=0;i<q;i+=magic){
        int L=i;
        int R=min(q,i+magic);
        /// [L;R)
//        cout<<"[L;R) :: ["<<L<<";"<<R<<")"<<"\n";

        memset(mark,0,sizeof(mark));
        vector<int> cur_mark;
        for (int j=L;j<R;j++){
            if (type[j]==1){
                mark[A[j]]=1;
                cur_mark.pb(A[j]);
            }
        }
        sort(all(cur_mark));
        cur_mark.resize(unique(all(cur_mark))-cur_mark.begin());

        memset(pref_value,0,sizeof(pref_value));
        for (int i=1;i<n;i++){
            if (!mark[i] && !mark[T.p[0][i]]){
//                cout<<"to push :: "<<i<<" with p("<<T.p[0][i]<<")\n";
                pref_value[i]=get_edge_w(a[i],a[T.p[0][i]]);
            }
        }
        dfs_push_value(0);

        for (int j=L;j<R;j++){
            if (type[j]==1){
                a[A[j]]=B[j];
            }
            else{
                int u=A[j];
                int v=B[j];
                int lca=T.lca(u,v);

                ll ans=0;
                ans+=pref_value[u];
                ans+=pref_value[v];
                ans-=2*pref_value[lca];

                G_T++;
                for (auto marked:cur_mark){
                    if (marked!=0 && (mark[marked] || mark[T.p[0][marked]]) && get_G(marked)==0 && T.is_edge_on_path(u,v,lca,marked,T.p[0][marked])){
                        set_G(marked,1);
                        ans+=get_edge_w(a[marked],a[T.p[0][marked]]);
                    }
                    if (len(reb[marked])!=0){
                        marked=reb[marked][0];

                        if (marked!=0 && (mark[marked] || mark[T.p[0][marked]]) && get_G(marked)==0 && T.is_edge_on_path(u,v,lca,marked,T.p[0][marked])){
                            set_G(marked,1);
                            ans+=get_edge_w(a[marked],a[T.p[0][marked]]);
                        }
                    }
                }
                auto lol=T.get_light_edges_down(u,v,lca);
                for (auto marked:lol){
                    if (marked!=0 && (mark[marked] || mark[T.p[0][marked]]) && get_G(marked)==0 && T.is_edge_on_path(u,v,lca,marked,T.p[0][marked])){
                        set_G(marked,1);
                        ans+=get_edge_w(a[marked],a[T.p[0][marked]]);
                    }
                }

                cout<<ans<<"\n";
            }
        }
    }
}