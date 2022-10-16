#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

const double PI = 4 * atan(1);

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

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
const int MAX = 1e5 + 5;
const int SQRT =  448;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash2 {
    int operator()(pair<int, int> x) const { return x.first* 31 + x.second; }
};
struct chash1 {
    int operator()(int x) const { return hash<int>{}(x ^ RANDOM); }
};
int n, m;
vector<pair<pii, int>> edges;
vi colors;
gp_hash_table<int, int, chash1> um;
map<pii, int> qConvert;
struct DSU{
    vi par, sz;
    vi vertices;
    int SZ;
    gp_hash_table<int, int, chash1> convert;
    void init(){///make sure you've added the vertices
        SZ = sz(vertices);
        f0r(i, SZ){
            convert[vertices[i]] = i;
        }
        f0r(i, SZ){
            par.eb(i);
            sz.eb(1);
        }
    }
    int get(int x){
        if(convert.find(x) == convert.end()){
            return -1;
        }
        x = convert[x];
        return getHelper(x);
    }
    int getHelper(int x){
        if(par[x] != x){
            par[x] = getHelper(par[x]);
        }
        return par[x];
    }
    bool unite(int x, int y){
        x = convert[x];
        y = convert[y];
        x = getHelper(x);
        y = getHelper(y);
        if(x == y){
            return false;
        }
        if(sz[x] < sz[y]){
            swap(x, y);
        }
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
};
vector<vi> comp;
vector<DSU> d;
vpi queries;
int ans [MAX];
int main(){
    fast_io();
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    f0r(i, m){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
       // cin >> u >> v >> c;
        u--; v--; c--;
        edges.eb(mp(mp(u, v), c));
        colors.eb(c);
    }
    sort(all(colors));
    set<int> s (all(colors));
    colors.assign(all(s));
    f0r(i, sz(colors)){
        um[colors[i]] = i;
    }
    f0r(i, m){
        edges[i].s = um[edges[i].s];
    }
    comp.resize(sz(colors));
    f0r(i, m){
        int u = edges[i].f.f;
        int v = edges[i].f.s;
        int c = edges[i].s;
        comp[c].eb(u);
        comp[c].eb(v);
    }
    f0r(i, sz(colors)){
        set<int> s1 (all(comp[i]));
        comp[i].assign(all(s1));
    }
    f0r(i, sz(colors)){
        DSU tmp;
        for(int x: comp[i]){
            tmp.vertices.eb(x);
        }
        tmp.init();
        d.eb(tmp);
    }

    f0r(i, m){
        int u = edges[i].f.f;
        int v = edges[i].f.s;
        int c = edges[i].s;
        d[c].unite(u, v);
    }

    int q;
    //cin >> q;
    scanf("%d", &q);
    f0r(i, q){
        int u, v;
        //cin >> u >> v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(u>v) swap(u, v);
        queries.eb(mp(u, v));
        qConvert[mp(u, v)] = 0;
    }
   // if(m == 99681) return 0;

    f0r(i, sz(colors)){
        if(sz(comp[i]) <= SQRT){
            f0r(it1, sz(comp[i])){
                f1r(it2, it1+1, sz(comp[i])){
                    int v1 = comp[i][it1];
                    int v2 = comp[i][it2];
                    if(v1>v2) swap(v1, v2);
                    if(d[i].get(v1) != d[i].get(v2)) continue;
                    if(qConvert.find(mp(v1, v2)) != qConvert.end()){
                        qConvert[mp(v1, v2)]++;
                    }
                }
            }
        }
        else{
            for(auto x: qConvert){
                int u = x.f.f;
                int v = x.f.s;
                int f1 = d[i].get(u);
                int f2 = d[i].get(v);
                if(f1 != -1 && f2 != -1 && f1 == f2){
                    qConvert[x.f]++;
                }
            }
        }
    }
    f0r(i, q){
        ans[i] = qConvert[queries[i]];
    }
    //f0r(i, q) cout << ans[i] << endl;
    f0r(i, q) printf("%d\n", ans[i]);
    return 0;
}