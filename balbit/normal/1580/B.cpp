#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define y1 zck_is_king
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

const int maxn = 1e2+5;

ll dp[maxn][maxn][maxn];
int P;
ll C[maxn][maxn];
ll fac[maxn];

ll F(int n, int k, int m) {
    if (dp[n][k][m] != -1) return dp[n][k][m];
    if (n == 0 || m > n) {
        if (k == 0) return fac[n];
        return 0;
    }
    if (k > n) return 0;
    if (m == 1) {
        if (k == 1) {
            return fac[n];
        }
        return 0;
    }
    dp[n][k][m] = 0;
    for (int a = 0; n-a-1 >= a; ++a) {
        int b = n-a-1;
        ll tt = 0;
        REP(k1, k+1) {
//            if (n == 4 && k == 2 && m == 3) {
//                bug(a,k1,m-1, b);
//                bug("AYO", F(a,k1,m-1));
//                bug("BYO", F(b,k-k1,m-1));
//            }
            tt += F(a, k1, m-1) * F(b,k-k1,m-1) % P ;
        }
        if (a != b) tt *= 2; tt %= P;
        tt = tt * C[n-1][a] % P;
        dp[n][k][m] += tt;
//        bug(a,b,tt);
    }
//    bug(n,k,m,dp[n][k][m]);
    return dp[n][k][m] %= P;

}

signed main(){
    IOS();
    memset(dp, -1, sizeof dp);
    int n,k,m;
    cin>>n>>m>>k>>P;
    fac[0] = 1;
    for (int i = 1; i<=n; ++i) fac[i] = fac[i-1] * i % P;
    REP(i,n+1) REP(j,n+1) {
        if (i >= j) {
            if (i==0 || j == 0) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % P;
        }
    }

    cout<<F(n,k,m)<<endl;

}