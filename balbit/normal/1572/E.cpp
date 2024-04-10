#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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

const int maxn = 200+5;

pair<int, ll> dp[maxn][maxn]; // max number of regions, then max range of the one on the current edge
int n,k;

ll x[maxn], y[maxn];

inline ll S(int i, int j, int k) {
    return abs(x[i] * y[j] + x[j] * y[k] + x[k] * y[i]
          -y[i] * x[j] - y[j] * x[k] - y[k] * x[i]); // shoelace that
}

ll A;

inline pair<int, ll> add(pair<int, ll> x, ll y) {
    return y + x.s >= A? pair<int, ll>{x.f+1,0} : pair<int, ll>{x.f, x.s + y};
}

bool ok() {
    REP(i,n) REP(j,n) {
        dp[i][j] = pair<int, ll>{0, 0};
    }
    for (int d = 1; d<n; ++d) {
        for (int i = 0; i+d<n; ++i) {
            int j = i+d;
            if (j == i+1) {
                dp[i][j] = {0,0};
            }else{
                MX(dp[i][j], add(dp[i+1][j], S(i,i+1,j)));
                MX(dp[i][j], add(dp[i][j-1], S(i,j-1, j)));
                for (int k = i+2; k<j-1; ++k) {
                    ll s = S(i,k,j);
                    if (dp[i][k].s + dp[k][j].s + s >= A) {
                        MX(dp[i][j], make_pair(dp[i][k].f + dp[k][j].f + 1,0));
                    }else{
                        MX(dp[i][j], make_pair(dp[i][k].f + dp[k][j].f, dp[i][k].s + dp[k][j].s + s));
                    }
                }
            }
            // try taking only one
//            bug(i,j,dp[i][j].f, dp[i][j].s);
        }
    }
//    bug(A, dp[0][n-1].f, dp[0][n-1].s);
    return dp[0][n-1].f >= k+1;
}

signed main(){
    IOS();
    cin>>n>>k;
    REP(i,n) {
        cin>>x[i]>>y[i];
    }
//    bug(S(0,1,0));
    x[n] = x[0]; y[n] = y[0];
//    A = 33;
//    ok();
    ll l = 0, r = 1e17;
    while (l!=r) {
        A = (l+r)/2;
        if (ok()) {
            l = A+1;
        }else{
            r = A;
        }
    }

    cout<<l-1<<endl;

//    A = 34;
//    ok();

}