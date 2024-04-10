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

ll dep[maxn];
int fa[21][maxn];
vector<int> g[maxn];
vector<int> leafs;
vector<pii> dl;

void dfs(int v, int p = -1) {
    fa[0][v] = p==-1?v:p;
    if (SZ(g[v]) == 1) leafs.pb(v), dl.pb({dep[v], SZ(leafs)-1  });
    for (int u : g[v]) {
        if (u != p) {
            dep[u] = dep[v] + 1;
            dfs(u,v);
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a,b);
    int need = dep[a] - dep[b];
    for (int j = 0; need != 0; ++j) {
        if (need & 1) a = fa[j][a];
        need/=2;
    }
    for (int j = 20; j>=0; --j) {
        if (fa[j][a] != fa[j][b]) a = fa[j][a], b = fa[j][b];
    }
    return a==b?a:fa[0][a];
}

int dst(int a, int b) {
    int c = lca(a,b);
    return dep[a] + dep[b] - 2*dep[c];
}

int L[maxn], R[maxn];
bool done[maxn];

void del(int x) {
    if (done[x]) return;
    done[x] = 1;
    int tl = L[x];
    if (L[x] != -1) R[L[x]] = R[x];
    if (R[x] != -1) {
        L[R[x]] = tl;
    }
}

signed main(){
    IOS();
    int n,k; cin>>n>>k;
    for (int i = 0; i<n-1; ++i){
        int a,b; cin>>a>>b; --a;--b;
        g[a].pb(b); g[b].pb(a);
    }
    int start = -1;
    for (int i = 0; i<n; ++i) {
        if (SZ(g[i]) != 1) {
            start = i; break;
        }
    }
    dfs(start);
    for (int j = 1; j<21; ++j){
        for (int i = 0; i<n; ++i) {
            fa[j][i] = fa[j-1][fa[j-1][i]];
        }
    }
    for (int i = 0; i<SZ(leafs); ++i) {
        L[i] = i-1;
        R[i] = (i==SZ(leafs)-1?-1:i+1);
    }
    sort(ALL(dl), greater<pii>());
    int re = 0;
    for (auto & ele : dl) {
        if (!done[ele.s]) { ++re;
            int v = ele.s;
            for (int at = v; at != -1; at = L[at]) {
                if (dst(leafs[at], leafs[v]) <= k) {
                    del(at);
                }else{
                    break;
                }
            }
            for (int at = R[v]; at != -1; at = R[at]) {
                if (dst(leafs[at], leafs[v]) <= k) {
                    del(at);
                }else{
                    break;
                }
            }
        }
    }
    cout<<re<<endl;
}