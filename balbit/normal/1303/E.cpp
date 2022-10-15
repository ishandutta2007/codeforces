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

const int maxn = 400+5;

int dp[maxn][maxn];

bool get(){
    string s, t; cin>>s>>t;
    int n = SZ(s); int m = SZ(t);

    for (int t2 = 0; t2 <= m; ++t2) {
        // where does t2 start in string t;
        memset(dp, -1, sizeof dp);
        dp[0][0] = t2;
        for (int i = 0; i<n; ++i) {
            for (int t1 = 0; t1 <= t2; ++t1) {
                if (dp[i][t1] != -1) {
                    MX(dp[i+1][t1], dp[i][t1]); // do nothing
                    if (dp[i][t1] < m && s[i] == t[dp[i][t1]]) {
                        MX(dp[i+1][t1], dp[i][t1]+1); // take one from seq 2
                    }
                    if (t1 < m && s[i] == t[t1]) {
                        MX(dp[i+1][t1+1], dp[i][t1]);
                    }
                }
            }
        }
        if (dp[n][t2] >= m) {
            return 1;
        }
    }
    return 0;
}

signed main(){
    IOS();
    int _; cin>>_;
    while(_--) {
        cout<<(get()?"YES":"NO")<<endl;
    }

}