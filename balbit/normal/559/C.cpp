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

const int iinf = 1<<29;
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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 2e5+5;

ll dp[maxn];
ll fac[maxn], ifac[maxn];

inline ll C(int a, int b){
    a += b;
    return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

signed main(){
    IOS();
    int h,c; cin>>h>>c;

    int n; cin>>n;
    fac[0] = ifac[0] = 1;
    vector<pii> v;
    for (int i = 1; i<maxn; ++i) {
        fac[i] = fac[i-1] * i % mod;
        ifac[i] = inv(fac[i]);
    }

    vector<int> p(n);
    for (int i = 0; i<n; ++i) {
        int r,c; cin>>r>>c;
        v.pb({r,c});
    }
    v.pb({1,1});
    sort(ALL(v), greater<pii> ());

    for (int i = 0; i<=n; ++i) {
        dp[i] = C(h-v[i].f, c-v[i].s);
        for (int j = 0; j<i; ++j){
            if (v[j].f >= v[i].f && v[j].s >= v[i].s) {
                dp[i] -= C(v[j].f - v[i].f, v[j].s - v[i].s) * dp[j];
                dp[i] %= mod; if (dp[i]<0) dp[i] += mod;
            }
        }
    }
    cout<<dp[n]<<endl;
}