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

const int maxn = 40+5;

int f[maxn];
int dp[maxn][maxn][2];
int s[maxn];

inline void add(int &a, int b) {a = (a+b);}

signed main(){
    IOS();
    int n; cin>>n;
    memset(s, -1, sizeof s);
    string S; cin>>S;
    int m = SZ(S);
    REP(i,m) {
//        char c; cin>>c;
        char c = S[i];
        s[i] = c - '0';
    }
    f[0] = f[1] = 0;
    for (int i = 2; i<=m; ++i) {
        f[i] = f[i-1];
        while (f[i]!=0 && s[f[i]] != s[i-1]) f[i] = f[f[i]];
        if (s[f[i]] == s[i-1]) ++f[i];
        bug(i, f[i]);
    }
//    assert(0);
    ll re=0;

    for (int st = 0; st <= m; ++st) {
        memset(dp, 0, sizeof dp);
        dp[0][st][0] = 1;

        REP1(i,n) {
//            int sig = 0;
            REP(j,m+1) {
                // j is the previous node
                REP(c, 2) {
                    // nw is the next character
//                    sig += dp[i-1][j][c];
                    int to = j;
                    while (to && s[to] != c) to = f[to];
                    if (s[to] == c) ++to;
//                    bug(to);
                    add(dp[i][to][1] , dp[i-1][j][1]);
                    add(dp[i][to][to==m] , dp[i-1][j][0]);
                }
            }
//            bug(sig);
        }
        bug(st, dp[n][st][1]);
        re += dp[n][st][1];
    }
    cout<<re<<endl;

}