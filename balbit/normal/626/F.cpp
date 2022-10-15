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

const int maxn = 3e3+5;

ll dp[2][1005][205];
int a[205];

signed main(){
    IOS();
    int n; cin>>n;
    int K; cin>>K;
    REP1(i,n) cin>>a[i];
    sort(a+1, a+n+1);
    dp[0][0][0] = 1;
    bool dpat = 0;
    ll re = 0;
    for (int i = 1; i<=n; ++i) {
//        bug(a[i] - a[i-1]);
        dpat ^= 1;
//        memset(dpat][])
        REP(m,n+1) {
//            int chg = (m-1) * (a[i] - a[i-1]);
            REP(j,K+1) {
                dp[dpat][j][m] = 0;
//                if (j - chg >= 0) {
                    for (int frm = m-1; frm <= m+1; ++frm) {
                        int chg = frm * (a[i] - a[i-1]);
                        if (j-chg >= 0 && frm >= 0) {
                            bug(chg, frm);
//                            if (frm == m+1 && frm > 1) {
//                                assert(0);
//                            }
                            if (frm == m+1)
                                dp[dpat][j][m] += dp[dpat^1][j-chg][frm] * frm % mod;
                            else if (frm == m)
                                dp[dpat][j][m] += dp[dpat^1][j-chg][frm] * (frm+1) % mod;
                            else
                                dp[dpat][j][m] += dp[dpat^1][j-chg][frm];
                        }
                    }
//                    dp[dpat][j][m] += (dp[dpat^1][j-chg][m-1]) + (dp[dpat^1][j-chg][m]) + (dp[dpat^1][j-chg][m+1]);
                    dp[dpat][j][m] %= mod;
                    if (i == n && m == 0) {
                        re += dp[dpat][j][m];
                    }
                    bug(i,j,m,dp[dpat][j][m]);
//                }
            }
        }
    }
    cout<<re % mod<<endl;

}