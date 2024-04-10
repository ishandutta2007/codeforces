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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

const int maxn = 2e5+5;

ll fac[maxn*2], ifac[maxn*2];

ll C(int a, int b) {
    if (a < b) return 0;
    return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

signed main(){
    IOS();

    fac[0] = ifac[0] = 1;
    for (int i = 1; i<maxn*2; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
    ifac[maxn*2-1] = inv(fac[maxn*2-1]);
    for (int i = maxn*2-2; i>=0; --i) {
        ifac[i] = ifac[i+1] * (i+1) % mod;
    }
    bug(fac[0], ifac[0]);
    bug(fac[3] * ifac[3] % mod);

    ll re = 0;
    int n; cin>>n;
    REP(i,n+1) {
        int a; cin>>a;
        re += C(a+i, i+1);
    }
    cout<<re%mod<<endl;

}