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

const int maxn = 3e5+5;

int w[maxn];

int A[maxn], B[maxn];
int par[maxn];
int find(int x) {
    return x == par[x]? x : find(par[x]);
}
vector<int>g[maxn];
bool dead[maxn];
int sz[maxn];
void mere(int a, int b ){
    a = find(a); b = find(b);
    if (a==b) return;
    if (sz[a] > sz[b]) swap(a,b);
    g[b].pb(a);
    sz[b]+=sz[a];
    par[a] = b;
    bug(a , "to", b );
}

int IT = 0;
int L[maxn], R[maxn];

pii s[maxn*4];

pii QU(int L, int R, int o = 1, int l = 0, int r = maxn-1){
    if (l > R || r < L) return {0,-1};
    if (l >= L && r <= R) {
        return s[o];
    }
    int mid = (l+r)/2;
    return max(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
}

void MO(int p, pii v, int o = 1, int l = 0, int r = maxn-1){
    if (l > p || r < p) return;
    if (l == r) {
        s[o] = v;
        return;
    }
    int mid = (l+r)/2;
    MO(p,v,o*2,l,mid);
    MO(p,v,o*2+1,mid+1,r);
    s[o] = max(s[o*2], s[o*2+1]);
//    return max(QU(L,R,o*2,l,mid), QU(L,R,o*2+1,mid+1,r));
}

bool seen[maxn];
void dfs(int v) {
    seen[v] = 1;
    L[v] = R[v] = IT++;
    MO(L[v], {w[v],L[v]});
    for (int u : g[v]) {
        if (!seen[u]){
            dfs(u);
        R[v] = R[u];

        }
    }
}



signed main(){
    IOS();

    int n,m,q; cin>>n>>m>>q;
    for (int i = 0; i<n; ++i) {
        par[i] = i; sz[i] = 1;
        cin>>w[i];
    }
    for (int i = 0; i<m; ++i) {
        int a,b; cin>>a>>b;
        --a; --b;
        A[i]=a; B[i] =b ;
    }
    vector<pii> v;
    for (int i = 0; i<q; ++i) {
        int t; cin>>t;
        int x; cin>>x; --x;
        v.pb({t,x});
        if (t == 2) {
            dead[x] = 1;
        }
    }
    for (int i = 0; i<m; ++i) {
        if (!dead[i]) {
            v.pb({2,i});
        }
    }
    vector<pii> ask;
    for (int i = SZ(v)-1; i>=0;--i){
        if (v[i].f == 2) {
            mere(A[v[i].s], B[v[i].s]);
        }else{
            int tp =find(v[i].s);
            bug(tp);
            ask.pb({tp, SZ(g[tp])});
        }
    }


    for (int i =0 ; i<n;++i) {
        if (!seen[i] && par[i]==i) dfs(i);
    }
    reverse(ALL(ask));
    for (pii pp : ask) {
        int x = pp.f;
        int rrr = L[x];
        if (pp.s) {
            rrr = R[g[x][pp.s-1]];
        }
        pii p = QU(L[x], rrr);
        bug(x, L[x], R[x], rrr);
        cout<<p.f<<endl;
        if (p.f){
            MO(p.s, {0,-1});
        }
    }
}