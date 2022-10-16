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
const int MAX = 1e5+5;
const int LOG = 20;
int n;
int w[MAX];
vi adj[MAX];
int even[MAX];
int odd[MAX];
int sz[MAX];
int bit = -1;
ll ans = 0;
ll cnt = 0;
int get(int x){
    if(w[x] & (1<<bit)){
        return 1;
    }
    return 0;
}
void dfs(int src, int par){
    odd[src] = 0; even[src] = 0;
    if(get(src) == 1){
        odd[src] += 1;
    }
    else{
        even[src] += 1;
    }
    for(int neigh: adj[src]){
        if(par != neigh){
            dfs(neigh, src);
            if(get(src)){
                even[src] += odd[neigh];
                odd[src] += even[neigh];
            }
            else{
                even[src] += even[neigh];
                odd[src] += odd[neigh];
            }
        }
    }
}
void add(int src, int par){
    int o = 0;
    int e = 0;
    if(get(src)){
        cnt += 1;
    }
    for(int neigh: adj[src]){
        if(par != neigh){
            if(get(src)){
                cnt += even[neigh];
                cnt += even[neigh]*e;
                cnt += odd[neigh]*o;
            }
            else{
                cnt += odd[neigh];
                cnt += even[neigh]*o;
                cnt += odd[neigh]*e;
            }
            e += even[neigh];
            o += odd[neigh];
            add(neigh, src);
        }
    }
}
void solve(){
    f0r(i, LOG){
        bit = i;
        cnt = 0;
        dfs(0, -1);
        add(0, -1);
        ans += (cnt*(1<<i));
    }
}
int main(){
    fast_io();
    cin >> n;
    f0r(i, n) cin >> w[i];
    f0r(i, n-1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    solve();
    cout << ans << endl;
    return 0;
}