#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const ll MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
static int n;
static vector<int> adj [MAX];
static vector<pair<int, int>> bad;
static int d [MAX];
template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];

    T comb(T a, T b) {
        return min(a,b);
    }

    void build(vector<T>& x) {
        for(int i = 0; i<x.size(); i++){
            stor[i][0] = x[i];
        }
        for(int j = 1; j<32 - __builtin_clz(SZ); j++){
            for(int i = 0; i< SZ - (1<<(j-1)); i++){
                stor[i][j] = comb(stor[i][j-1],stor[i+(1<<(j-1))][j-1]);
            }
        }
    }

    T query(int l, int r) {
        int m = 31-__builtin_clz(r-l+1);
        return comb(stor[l][m],stor[r-(1<<m)+1][m]);

    }
};
template<int SZ> struct LCA {
    vector<int> adj[SZ];
    RMQ<pair<int, int>,2*SZ> r;
    vector<pair<int, int>> tmp;
    int depth[SZ], pos[SZ];

    int N, R = 1;

    void addEdge(int u, int v) {
        u += 1;
        v += 1;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    void dfs(int u, int prev){
        pos[u] = tmp.size(); depth[u] = depth[prev]+1;
        tmp.push_back({depth[u],u});
        for (int v: adj[u]){
            if (v != prev) {
                dfs(v, u);
                tmp.push_back({depth[u],u});
            }
        }
    }

    void init(int _N) {
    	N = _N;
        dfs(R, 0);
        r.build(tmp);
        for(int i = 0; i<SZ - 1; i++){
            d[i] = depth[i+1];
        }
    }

    int lca(int u, int v){
        u += 1;
        v += 1;
        u = pos[u], v = pos[v];
        if (u > v) {
            swap(u,v);
        }
        return r.query(u,v).second - 1;
    }

    int dist(int u, int v) {
        u += 1;
        v += 1;
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    }
};
static int cnt [MAX][3]; //0 is start, 1 is stop, 2 is lca
ll calc(int x){
    ll ans = 1;
    ll ret = 2;
    while(x>0){
        if(x%2 == 1){
            ans = ans*ret;
            ans = ans % MOD;
        }
        x = x/2;
        ret = ret*ret;
        ret = ret%MOD;
    }
    return ((ans -1))%MOD;
}
static int a1 [MAX];
static int a2[MAX];
static int a3[MAX];
static int vis[MAX];
int dfs1(int src){
    int ans = cnt[src][0];
    vis[src] = 1;
    for(int x: adj[src]){
        if(vis[x] == 0){
            ans += dfs1(x);
        }
    }
    a1[src] = ans ;
    return ans;
}
int dfs2(int src){
    int ans = cnt[src][1];
    vis[src] = 1;
    for(int x: adj[src]){
        if(vis[x] == 0){
            ans += dfs2(x);
        }
    }
    a2[src] = ans;
    return ans;
}
int dfs3(int src){

    int ans = cnt[src][2];
    vis[src] = 1;
    for(int x: adj[src]){
        if(vis[x] == 0){
            ans += dfs3(x);
        }
    }
    a3[src] = ans ;
    return ans;
}
int main(){
    fast_io();
    int n, k;
    cin >> n;
    LCA<100005> lca;
    f0r(i, n-1){
        int a, b, x;
        cin >> a>>b >>x;
        a--;
        b--;
        lca.addEdge(a, b);
        if(x == 1){
            bad.eb(mp(b, a));
        }
        adj[a].eb(b);
        adj[b].eb(a);

    }
    lca.init(n);

    int prev = 0;
    cin >> k;
    f0r(i, k){
        int s;
        cin >> s;
        s--;
        cnt[prev][0] +=1;
        cnt[s][1] += 1;
        int ancestor = lca.lca(prev, s);
        //cout << s << " " << prev << " " << ancestor << " a" << endl;
        cnt[ancestor][2] += 1;
        prev = s;
    }
    f0r(i, n){
        vis[i] = 0;
    }

    dfs1(0);
    f0r(i, n){
        vis[i] = 0;
    }
    dfs2(0);
    f0r(i, n){
        vis[i] = 0;
    }
    dfs3(0);
    ll ans = 0;
    for(int i= 0; i<bad.size(); i++){
        int a = bad[i].f;
        int b = bad[i].s;
        if(d[a] > d[b]){
            ans += calc(a1[a] - a3[a]);
          //  cout << " hi " << endl;
        }
        else{
               // cout << " no " << endl;
            ans += calc(a2[b] - a3[b]);
        }
        ans = ans % MOD;
    }
    cout << ans << endl;
    return 0;
}