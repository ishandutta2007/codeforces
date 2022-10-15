#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 2e3+5;

ll pdis[maxn][maxn], sig[maxn];
// sig is sigma i:0~b,  p^i * (1-p)^(b-i)
ll pscc[maxn], dp[maxn];
ll P[maxn*maxn], P1[maxn*maxn]; // powers of P and P1
ll C[maxn][maxn];
ll p, p1;

#define REP(i,n) for (int i = 0; i<n; ++i)

void build(){
    P[0] = P1[0] = 1;
    p1 = (1-p+mod) % mod;
    for (int i = 1; i<maxn*maxn; ++i) {
        P[i] = P[i-1] * p % mod;
        P1[i] = P1[i-1] * p1 % mod;
    }
    sig[0] = 1;
    for (int i = 1; i<maxn; ++i) {
        sig[i] = sig[i-1] * p1 + P[i];
        sig[i] %= mod;
    }
    C[0][0] = 1;
    for (int i = 0; i<maxn; ++i) for (int j = 0; j<=i; ++j) {
        if (i == 0 || j == 0) C[i][j] = 1;
        else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    ll AA, BB; cin>>AA>>BB;
    p = AA * inv(BB) % mod;
    build();
    bug(p, p1);
    for (int b = 0; b<=n; ++b) {
        for (int a = 0; a <= n; ++a) {
            if (b==0 || a == 0) pdis[b][a] = 1;
            else {
                pdis[b][a] = pdis[b][a-1] * P[b] % mod * a %mod+ pdis[b-1][a] * P1[a] % mod * b % mod;
                pdis[b][a] %= mod;
                pdis[b][a] *= inv(b+a);
                pdis[b][a] %= mod;
            }


            bug(b,a, pdis[b][a]);
        }
    }
    bug(sig[3]);
    pscc[1] = 1;
    for (int i = 2; i<=n; ++i) {
        pscc[i] = 1;
        for (int j = 1; j<i; ++j) {
            pscc[i] -= pscc[j] * C[i][j] % mod * (pdis[i-j][j]) % mod;
            if (pscc[i] < 0) pscc[i] += mod;
        }
        bug(i, pscc[i]);
    }
    dp[0] = dp[1] = dp[2] = 0;
    for (int i = 3; i<=n; ++i) {
        ll me = i * (ll)(i-1) / 2; me %= mod;
        dp[i] %= mod;
        for (int j = 1; j<i; ++j) {
//            bug(i, j, C[i][j] * pscc[j] % mod * pdis[i-j][j] % mod);
            dp[i] += C[i][j] * pscc[j] % mod * pdis[i-j][j] % mod * (( dp[i-j] + (j * (ll) (j-1) / 2) % mod + dp[j] % mod )%mod) % mod ;
            dp[i] %= mod;
        }
        dp[i] += me * pscc[i] % mod;
        dp[i] %= mod;
        ll tome = (1-pscc[i]+mod) % mod;
        dp[i] *= inv(tome);
        dp[i] %= mod;
        bug(i, dp[i]);
    }
    ll me = (n) * (ll) (n-1) / 2 % mod;
    cout<< (dp[n]+me) % mod <<endl;

}