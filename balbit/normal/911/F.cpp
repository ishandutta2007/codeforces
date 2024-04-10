#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif
 
#define int ll
 
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
 
 
void GG(){cout<<"-1\n"; exit(0);}
 
ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}
 
ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}
 
const int maxn = 1e6+5;
 
vector<int> g[maxn];
bool dia[maxn];
int dep[maxn];
pii bst = {0,0};
int rt, oth;

void dfs(int v, int p = -1){
    MX(bst, make_pair(dep[v],v));
    for (int u : g[v]) {
        if (u!=p) {
            dep[u] = dep[v]+1;
            dfs(u,v);
        }
    }
}

vector<int> vd;
int better;
int node = 0;
ll re = 0;

vector<pii > ans;

void dad(int v, int p = -1){
    re += dep[v] + better;
    for (int u : g[v]){
        if (u!=p){
            dep[u] = dep[v] +1; dad(u,v);
        }
    }
    ans.pb({node+1,v+1});
}
bool dd(int v, int p = -1){
    if (v == oth) {
        vd.pb(v); return dia[v] = 1;
    }
    for (int u : g[v]) {
        if (u!=p && dd(u,v)) {
            vd.pb(v); return dia[v] = 1;
        }
    }return 0;
}

int d[maxn];

main(){
    IOS();
    int n; cin>>n;
    REP(i,n-1) {
        int a,b; cin>>a>>b; a--; b--; d[a]++; d[b]++; g[a].pb(b); g[b].pb(a);
    }
    dfs(0);
    rt = bst.s; fill(dep, dep+maxn, 0); dfs(rt);
    oth = bst.s; dd(rt);
    bug(rt, oth);
    int dl = SZ(vd);
    bug(dl);
    REP(i, dl){
         better = max(i, dl-1-i);
         if (i < dl-1-i) node = rt;
         else node = oth;
         for (int u : g[vd[i]]) {
              if (!dia[u]) {
                  dep[u] = 1; dad(u, vd[i]);
              }
         }
    }
    REP(i, dl-1) {
        ans.pb({vd.back()+1,vd[i]+1});
    }
    re += dl * (ll)(dl-1) / 2;
    cout<<re<<endl;
    for (pii & x : ans){
        cout<<x.f<<' '<<x.s<<' '<<x.s<<endl;
    }
}