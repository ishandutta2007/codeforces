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

ll dp[maxn][4];
ll fee[maxn], nf[maxn];

signed main(){
    IOS();
    memset(dp, 0x3f, sizeof dp);
    int n; cin>>n;
    int r1,r2,r3; cin>>r1>>r2>>r3; // pistol, laser, awp
    int d; cin>>d;
    vector<int> a(n+1);
    ll re = 0;
    dp[0][2] = 0;
    for (int i = 1; i<=n; ++i) {
        cin>>a[i];
        nf[i] = min(r1,r3) * a[i] + r3;
        fee[i] = min({
                                                             min(r1,r3) * a[i] + r3,
                                                             min(r1, r3) * (a[i] + 2),
                                                             r2 + min({r1,r2,r3})
                                                            });
        if (1) {
//            dp[i][0] = dp[i-1][0]+ nf[i];
            dp[i][1] = min(dp[i-1][2], dp[i-1][1]) + 2*d + fee[i];
            dp[i][2] = min(dp[i-1][1] +fee[i], dp[i-1][2] + nf[i]) ;
            dp[i][3] = min((i!=n?(min(dp[i-1][2], dp[i-1][1]) + (n-i) * d):0x3f3f3f3f3f3f3f3f), dp[i-1][3]) + (i==n?min(nf[i],2*d+fee[i]):fee[i]);
            bug(i, dp[i][3]);
        }
    }
    bug(dp[n][0], dp[n][1], dp[n][2], dp[n][3]);
//    ll ty2 = dp[n][0] + fee[n-1] + fee[n] - nf[n-1] - nf[n] + 2*d;
//    bug(ty2);
    cout<<min({dp[n][1], dp[n][2], dp[n][3]}) + d * (n-1)<<endl;
}