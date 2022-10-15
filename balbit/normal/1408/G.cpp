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
//const ll mod = 1e9+7 ;

const ll mod = 998244353 ;
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

const int maxn = 1505;

int nof[maxn];
int par[maxn];

int w[maxn][maxn];

int ishead[maxn];
vector<int> here[maxn];
int find(int x) {return x == par[x]? x : par[x] = find(par[x]);}

int gpar[maxn*2];
int IT = 0;

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a != b) {
        if (SZ(here[a]) > SZ(here[b])) swap(a,b);
        for (int x : here[a]) here[b].pb(x);
        nof[b]+=nof[a]+1;
        par[a] = b;
        a = b;
    }else{
        ++ nof[a];
    }
    bug(nof[b], SZ(here[b]));
    if (nof[b] == SZ(here[b]) * (SZ(here[b]) - 1) / 2) {
        bug("henlo");
        for (int x : here[b]) {
            if (ishead[x]!= -1) {
                gpar[ishead[x]] = IT;
                ishead[x] = -1;
            }
        }
        ishead[b] = IT++;
    }
}

vector<int> g[maxn*2];
vector<ll> dp[maxn*2];

#define REP(i,n) for (int i = 0; i<n; ++i)

void NTT(vector<ll> &a, ll mo, bool rev=0){
    // mo has to be 2^k * c + 1
    int n = SZ(a);
    while ((n&(-n))!=n) {
        a.pb(0); n++;
    }
    for (int i = 1, j = 0; i<n; i++){
        int bit = n>>1;
        while (j>=bit) j-=bit, bit>>=1; j+=bit;
        if (i<j) swap(a[i], a[j]);
    }
    for (int B = 2; B<=n; B*=2){
        ll w0 = mpow(3,(mo-1)/(B),mo);
        for (int i = 0; i<n; i+=B){
            ll w = 1;
            for (int j = 0; j<B/2; j++){
                ll u = a[i+j], v = w*a[i+j+B/2]%mo;
                a[i+j] = u+v, a[i+j+B/2] = u-v;
                if (a[i+j]>=mo) a[i+j]-=mo; if (a[i+j+B/2]<0) a[i+j+B/2]+=mo;
                w = w*w0%mo;
            }
        }
    }
    if (rev) {
        reverse(next(a.begin()),a.end());
        ll invn = inv(n,mo);
        REP(i,n) a[i] = a[i]*invn%mo;
    }
}
vector<ll> mul (vector<ll> a, vector<ll> b, ll mo = mod){
    int n = 1; while (n < SZ(a) + SZ(b)) n*=2;
    vector<ll> x(n), y(n);
    REP(i, SZ(a)) x[i] = a[i]; REP(j, SZ(b)) y[j] = b[j];
    NTT(x,mo); NTT(y,mo);
    REP(i, n) x[i] = x[i] * y[i] % mo;
    NTT(x,mo,1);
    while (x.size()>1 && x.back()==0) x.pop_back(); return x;
}

int n;

void dfs(int v) {
    bug(v);
    vector<ll> mydp (n+1,0);
//    mydp[0] = 1;
    bool done = 0;
    for (int u : g[v]) {
        dfs(u);
        if (done)
            mydp = mul(mydp, dp[u]);
        else
            mydp = dp[u];
        done = 1;
    }
//    mydp[0] = 0;
    (mydp[1] += 1) %= mod;
    dp[v] = mydp;
    bug(v);
//    for (int j = 0; j<=n; ++j) {
//        cout<<mydp[j]<<' ';
//    }
//    cout<<endl;

}

int a[maxn][maxn];

signed main(){
    IOS();
    memset(gpar, -1, sizeof gpar);
    cin>>n;
    vector<pair<int, pii> > ed;
    for (int i = 0; i<n; ++i) {
        here[i].pb(i);
        ishead[i] = IT++;
        par[i] = i;
        nof[i] = 0;
        for (int j = 0; j<n; ++j) {
            cin>>a[i][j];
            if (i > j) {
                ed.pb({a[i][j], {i,j}});
            }
        }
    }
    sort(ALL(ed));
//    reverse(ALL(ed));
    for (auto & p : ed) {
        int a = p.s.f, b = p.s.s;
        merge(a,b);
    }

    int rt = find(0);
    for (int i = 0; i<IT; ++i) {
        bug(i, gpar[i]);
        if (gpar[i] != -1)
            g[gpar[i]].pb(i);
    }
    rt = IT-1;
    dfs(rt);
    bug(rt, IT);
    for (int i = 1; i<=n; ++i) cout<<dp[rt][i]<<' ';
}