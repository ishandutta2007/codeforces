#include <bits/stdc++.h>
//#pragma GCC optimize
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

const int maxn = 82;

int pos[maxn];
const int maxsig = maxn * maxn / 2 / 2 + 1;
int dp[maxn][maxn][maxsig];

int m = 0;

signed main(){
    IOS();
    int n; cin>>n;
    int mxs = (n) * (n-1) / 2 / 2 + 3;
    bug(mxs);
    int n0 = 0;
    for (int i = 1; i<=n; ++i) {
        int x; cin>>x;
        if (x ) {
            ++m; pos[m] = i;
        }else n0 ++;
    }

    bug(m);

    pos[m+1] = n+1;

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;

    for (int j = 1; j<=m+1; ++j) {
        for (int i = j; i<=n+1; ++i) {
            for (int sig = 0; sig < mxs; ++sig) {
                if (sig - abs(i-pos[j]) < 0) continue;
                for (int prev = 0; prev < i; ++prev) {
                    dp[j][i][sig] = min(dp[j][i][sig], dp[j-1][prev][sig - abs(i - pos[j])] + (i - prev - 2) * (i - prev-1) / 2);
                }
                bug(dp[j][i][sig], j,i,sig);
            }
        }
    }
    bug(dp[1][2][1]);
    int tmp = 0;
    for (int i = 0; i<= n * (n-1) / 2; ++i) {
        if (i < mxs) {
            tmp = max(tmp, n0 * (n0-1) / 2 - dp[m+1][n+1][i] );
        }
        cout<<tmp<<' ';
    }


}