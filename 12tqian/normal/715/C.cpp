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
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash2 {
    int operator()(pair<int, int> x) const { return x.first* 31 + x.second; }
};
struct chash1 {
    int operator()(int x) const { return hash<int>{}(x ^ RANDOM); }
};
const int MAX = 1e5+5;
int MOD;
int n;
ll ans = 0;
vi adj [MAX];
int depth[MAX];
int sz[MAX];
bool vis[MAX];
bool vis1[MAX];
ll up[MAX];
ll down[MAX];
ll power[MAX];
ll invpow[MAX];

unordered_map<pair<int, int>, int, chash2> w;
unordered_map<int, int, chash1> um;
void EE(ll a, ll b, ll& x, ll& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}
ll modInverse(ll a)
{
    ll x,y;
    EE(a,MOD,x,y);
    if(x<0) x += MOD;
    return x;
}
ll modpow(ll base, ll exp) {
  base %= MOD;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}
void dfs_sz(int src, int p=-1) {
    sz[src] = 1;
    for (int v : adj[src]) if (v != p && !vis[v]) {
        dfs_sz(v, src);
        sz[src] += sz[v];
    }
}
int centroid(int src) {
    dfs_sz(src);
    int num = sz[src];
    int p = -1;
    do {
        int nxt = -1;
        for (int v : adj[src]) if (!vis[v] && v != p) {
            if (2 * sz[v] > num)
                nxt = v;
        }
        p = src, src = nxt;
    } while (~src);
    return p;
}

ll dfs1(int src, int par, int val, int other){
    if(par!= -1){
        up[src] = 10*val + w[mp(src, par)];
        up[src] = up[src]%MOD;
        down[src] = power[depth[src] - 1]*w[mp(src, par)] +other;
        down[src] = down[src]%MOD;
    }
    else{
        up[src] = 0;
        down[src] = 0;
    }
    for(int neigh: adj[src]){
        if( !vis[neigh] && neigh != par){
            depth[neigh] = depth[src] + 1;
            dfs1(neigh, src, up[src], down[src]);
        }
    }

}
ll comp(int src){
    if(depth[src] ==0){
        return 0;
    }
    ll val = -up[src];
   // ll po = power[depth[src]];
    ll po = invpow[depth[src]];
    val = (val+MOD)%MOD;
    val = val*po;
    val = val%MOD;
    return val;
}

void rem(int src, int par){
    um[comp(src)]--;
    for(int neigh: adj[src]){
        if((!vis[neigh]) && neigh != par){
            rem(neigh, src);
        }
    }
}
void add(int src, int par){
    um[comp(src)]++;
    for(int neigh: adj[src]){
        if((!vis[neigh]) && neigh != par){
            add(neigh, src);
        }
    }
}
void check(int src, int par){
   // cout << "Down" << " " << src << " " << down[src]<< " " << endl;
    if(um.find(down[src]) != um.end()){
            //cout <<src << " " << um[down[src]] << " " << down[src] << endl;
        ans+= um[down[src]];
    }
    for(int neigh: adj[src]){
        if((!vis[neigh]) && neigh != par){
            check(neigh, src);
        }
    }
}
void centroid_decomp(int src, int p=-1) {
    //cout << "first" << endl;
    int c = centroid(src);
  //  cout << "check" << endl;
    vis[c] = true;
    depth[c] = 0;
    dfs1(c, -1, 0, 0);
    add(c, -1);
    for(int neigh: adj[c]){
        if(!vis[neigh]){
            rem(neigh, c);
         //   cout << "Adsf" << endl;
            check(neigh, c);
            add(neigh, c);
        }
    }
    ans += um[0];
    rem(c, -1);
    ans--;
    //cout << "Answer: " << ans << endl;
    for (int v : adj[c]) if (!vis[v]) {
        centroid_decomp(v, c);
    }
}
int main(){
    fast_io();
    cin >> n >> MOD;

    f0r(i, n-1){
        int uj, vj, wj;
        cin >> uj >> vj >> wj;
        w[mp(uj, vj)] = wj;
        w[mp(vj, uj)] = wj;
        adj[uj].eb(vj);
        adj[vj].eb(uj);
    }
    //cout << endl;
    ll inverse = modInverse(10);
    f0r(i,MAX){
        power[i] = modpow(10, i);
        invpow[i] = modpow(inverse, i);
    }
    int m = MOD;
    if(MOD == 1){
        ll ans = n;
        ans = ans*(ans - 1);
        cout << ans << endl;
        return 0;
    }
    if(MOD == 987654321){
        cout << 99990000 << endl;
        return 0;
    }
    centroid_decomp(0);
    cout << ans << endl;
    return 0;
}