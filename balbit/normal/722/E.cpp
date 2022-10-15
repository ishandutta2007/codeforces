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

ll dp[2003][22];
ll fac[200006],ifac[200006];

inline ll CC(int a, int b) {
    a = a+b;
    return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

int R[2003],C[2003];

signed main(){
    IOS();
    fac[0] = ifac[0] = 1;
    REP1(i, 200006) {
        fac[i] = fac[i-1] * i % mod;
        ifac[i] = inv(fac[i]);
    }
    int n,m,k,s; cin>>n>>m>>k>>s;
    vector<pii> v;
    v.pb({1,1});
    v.pb({n,m});
    REP(i,k) {
        int r,c; cin>>r>>c; v.pb({r,c});
    }
    sort(ALL(v));

    REP1(i,SZ(v)-1) {
        R[i] = v[i].f, C[i] = v[i].s;
        dp[i][0]=CC(R[i]-1, C[i]-1);
        REP(fk, 21) {
            REP1(j,i-1) {
                if (R[j] <= R[i] && C[j] <= C[i] ) {
                    dp[i][fk] -= dp[j][fk] * CC(R[i]-R[j], C[i]- C[j]) % mod;
                    if (dp[i][fk] < 0) dp[i][fk] += mod;
                    dp[i][fk+1] += dp[j][fk] * CC(R[i]-R[j], C[i]- C[j]) % mod;
                    if (dp[i][fk+1] >= mod) dp[i][fk+1] -= mod;
                }
            }
        }
    }
    ll re=  0;
    REP(fk, 22) {
        re += dp[SZ(v)-1][fk] * s % mod;
        bug(fk, dp[SZ(v)-1][fk])
        s = (s+1)/2;
    }
    cout<<re*inv(CC(n-1,m-1))%mod<<endl;

}