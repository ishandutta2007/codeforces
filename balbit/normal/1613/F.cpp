#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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
const ll mod = 998244353;


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

const int maxn = 2.5e5+5;

vector<int> g[maxn];
int deg[maxn];
vector<int> d;

void dfs(int v, int p) {
    for (int u : g[v]) {
        if (u != p) {
            dfs(u,v);
            ++deg[v];
        }
    }
}

void NTT(vector<ll> &a, bool rev=0){
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
        ll w0 = mpow(3,(mod-1)/(B),mod);
        for (int i = 0; i<n; i+=B){
            ll w = 1;
            for (int j = 0; j<B/2; j++){
                ll u = a[i+j], v = w*a[i+j+B/2]%mod;
                a[i+j] = u+v, a[i+j+B/2] = u-v;
                if (a[i+j]>=mod) a[i+j]-=mod; if (a[i+j+B/2]<0) a[i+j+B/2]+=mod;
                w = w*w0%mod;
            }
        }
    }
    if (rev) {
        reverse(next(a.begin()),a.end());
        ll invn = inv(n,mod);
        REP(i,n) a[i] = a[i]*invn%mod;
    }
}
vector<ll> mul (vector<ll> a, vector<ll> b){
    int n = 1; while (n < SZ(a) + SZ(b)) n*=2;
    vector<ll> x(n), y(n);
    REP(i, SZ(a)) x[i] = a[i]; REP(j, SZ(b)) y[j] = b[j];
    NTT(x); NTT(y);
    REP(i, n) x[i] = x[i] * y[i] % mod;
    NTT(x,1);
    while (x.size()>1 && x.back()==0) x.pop_back(); return x;
}


vector<ll> dnc(int l, int r) {
    bug(l,r);
    if (l == r) {
        return {1, d[l]};
    }
    int mid = (l+r)/2;
    return mul(dnc(l,mid), dnc(mid+1,r));
}

ll fac[maxn];

signed main(){
    IOS();
    fac[0] = 1;
    for (int i = 1; i<maxn; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
    int n; cin>>n;
    REP(i,n-1) {
        int a,b; cin>>a>>b;--a; --b; g[a].pb(b); g[b].pb(a);
    }
    dfs(0, -1);
    REP(i,n) {
        bug(i, deg[i]);
        if (deg[i]) {
            d.pb(deg[i]);
        }
    }
//    return 0;
    vector<ll> hi = dnc(0, SZ(d)-1);

    ll re = 0;

    REP(i, SZ(hi)) {
        bug(i, hi[i]);
        re += (i%2==0?1:-1) * hi[i] * fac[n-i] % mod;
        re %= mod;
    }
    cout<<(re+mod)%mod<<endl;


}