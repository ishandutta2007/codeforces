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
const ll mod = 998244353 ;


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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 3e3+5;

ll dp[maxn][maxn];
string s, t;

signed main(){
    IOS();
    cin>>s>>t;
    int n = s.length(), m = t.length();
    for (int i = 0; i<n+1; ++i) dp[i+1][i] = 1;
    ll re = 0;
    for (int d = 0; d<n; ++d) {
        for (int l = 0; l<n; ++l) {
            int r = l+d; if (r >= n) break;
            dp[l+1][r+1] = 0;
            if (r >=m || t[r] == s[r-l]) dp[l+1][r+1] += dp[l+1][r-1+1];
            if (l >=m || t[l] == s[r-l]) dp[l+1][r+1] += dp[l+1+1][r+1];
            dp[l+1][r+1] %= mod;
                bug(l,r,dp[l+1][r+1]);
            if (l == 0 && r >= m-1) {
                re += dp[l+1][r+1];
                re %= mod;
            }
        }
    }
    cout<<re<<endl;

}