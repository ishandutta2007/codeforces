#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e6+5;

int n,k;
vector<int> tree[maxn];
vector<int> g[maxn], gt[maxn];
vector<int> ord;
bool isleaf[maxn];

void dfs(int v, int p) {

    ord.pb(v);
    // draw line from v to kth parent
    bool go = 0;
    for (int u : tree[v]) {
        if (u == p) continue;
        g[v].pb(u);
        go  =1;
        dfs(u,v);
    }
    isleaf[v] = !go;
    ord.pop_back();
    if (!go){
        int kpar = ord[max(0,SZ(ord) - k)];
        g[v].pb(kpar);
    }
}

vector<int> kord;
bool seen[maxn];
void d2(int v) {
    seen[v] = 1;
    for (int u : g[v]) {
        if (!seen[u]) {
            d2(u);
        }
    }
    kord.pb(v); // postorder
}

int nscc=0;
int scc[maxn];
int sval[maxn];

void d3(int v) {
    scc[v] = nscc;
    sval[nscc] += isleaf[v];
    seen[v] = 1;
    for (int u : gt[v]) {
        if (!seen[u]) {
            d3(u);
        }
    }
}

int dp[maxn];

signed main(){
    IOS();

     cin>>n>>k;
    for (int i = 1; i<n; ++i) {
        int p; cin>>p;
        tree[p-1].pb(i);
    }

    dfs(0,0);
    // build gt
    for (int i = 0; i<n; ++i) {
        for (int x : g[i]) {
            gt[x].pb(i);
        }
    }

    for (int i = 0; i<n; ++i) {
        if (!seen[i]) {
            d2(i);
        }
    }
    bug(SZ(kord));
    memset(seen, 0, sizeof seen);
    for (int i = n-1; i>=0; --i) {
        bug(i, kord[i]);
        if (!seen[kord[i]]){
            ++nscc;
            d3(kord[i]);
            bug(i, nscc);
        }
    }
    bug(nscc);
    for (int i = 0; i<=nscc; ++i) dp[i] = sval[i];
    // the scc graph should be a tree (?????)
    for (int i = 0; i<n; ++i) {
        int v = kord[i];
        for (int u : g[v]) {
            if (scc[u] == scc[v]) continue;
            dp[scc[v]] = max(dp[scc[v]], sval[scc[v]] + dp[scc[u]]);
        }
    }
    cout<<dp[scc[0]]<<endl;
}