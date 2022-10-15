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

const int maxn = 1e5+5;

int dp[205][205*26];

signed main(){
    IOS();

    int n,k; cin>>n>>k;
    bool at = 0;
    REP(j, k+1) REP(s, n*26+1) {
        dp[j][s] = -iinf;
    }
    dp[0][0] = 0;
    REP(i,n) {
//        memset(dp[at^1],0,sizeof dp[at^1]);
        ll t; cin>>t;
        int n2 = 0, n5 = 0;
        while (t%2==0) {
            ++n2; t/=2;
        }
        while (t%5 == 0) {
            ++n5; t/=5;
        }
        bug(n2,n5);
        RREP(j,k+1) {
            RREP(cnt, i*26+1) {
                MX(dp[j+1][cnt+n5],dp[j][cnt]+n2);
            }
        }
    }
    int re = 0;
    REP(j,k+1) REP(cnt,n*26+1) {
        MX(re, min(cnt, dp[j][cnt]));
        bug(cnt, dp[j][cnt]);
    }
    cout<<re<<endl;
}