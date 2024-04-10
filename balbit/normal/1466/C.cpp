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

const int maxn = 1e5+5;


int dp[maxn][2][2];
char s[maxn];

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
//        int n; cin>>n;
        string S; cin>>S;
        int n = SZ(S);
        for (int i = 1; i<=n+1; ++i) {
            memset(dp[i], 0x3f, sizeof dp[i]);
        }
//        dp[0][0][1] = 0;
        int re = n;
        REP1(i,n) {
            s[i] = S[i-1];
            REP(x,2) REP(y,2) {
                if (!x && !y && i>1 && s[i] == s[i-1]) continue;
                REP(k,2) {
                    if (i>2 && !k && !x && s[i-1] == s[i-2]) continue;
                    if (i>2 && !k && !y && s[i] == s[i-2]) continue;
                    dp[i][x][y] = min(dp[i][x][y], dp[i-1][k][x] + y);
                }
                if (i == n) {
                    re = min(re, dp[i][x][y]);
                }
            }
        }
        cout<<re<<endl;
    }

}