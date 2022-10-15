#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 1e5+5;

ll dp[3003][105][2];

signed main(){
    IOS();
    int n, l; cin>>n>>l;
    vector<pii> v;
    set<pii> st;
    REP(i,n) {
        int a, b; cin>>a>>b;
//        if (st.count({a,b}) || st.count({b,a})) continue;
        v.pb({a,b});
//        st.insert(v.back());
    }
    n = SZ(v);
    bug(n);
    dp[0][n][0] = dp[0][n][1] = 1;
    REP1(i,l) {
        REP(it,n) {
            int x = v[it].f;
            if (i-x>=0) {
                REP(j,n+1) {
                    if (j!=it && (j==n || v[j].s==x)) {
                        dp[i][it][0] += dp[i-x][j][0];
                    }else if (j!=it && (j==n || v[j].f==x)) {
                        dp[i][it][0] += dp[i-x][j][1];
                    }
                }
            }
            x = v[it].s;
            if (i-x >= 0 && v[it].f!=v[it].s) {
                REP(j,n+1) {
                    if (j!=it && ((j==n) || (v[j].s==x))) {
                        dp[i][it][1] += dp[i-x][j][0];
                    }
                    else if (j!=it && ((j==n) || (v[j].f==x))) {
                        dp[i][it][1] += dp[i-x][j][1];
                    }
                }
            }
            dp[i][it][0] %= mod;
            dp[i][it][1] %= mod;
        }
    }
    ll re= 0;
    REP(it,n) {
        re += dp[l][it][0] + dp[l][it][1];
        bug(it, dp[l][it][0] , dp[l][it][1])
    }
    cout<<re%mod<<endl;
}