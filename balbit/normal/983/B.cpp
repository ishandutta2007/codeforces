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

const int maxn = 5e3+5;

int a[maxn];
int dp[maxn][maxn];
int ans[maxn][maxn];

signed main(){
    IOS();
    int n; cin>>n;
    REP(i,n) {
        cin>>a[i];
    }
    for (int l = 1; l<=n; ++l) {
        for (int i = 0; i+l<=n; ++i) {
            if (l == 1) {
                dp[l][i] = a[i];
            }else{
                dp[l][i] = dp[l-1][i] ^ dp[l-1][i+1];
            }
            ans[i][i+l-1] = dp[l][i];
            if (l != 1)
            ans[i][i+l-1] = max({ans[i][i+l-1], ans[i+1][i+l-1], ans[i][i+l-2]});
        }
    }

    bug(ans[0][n-1]);
    int q; cin>>q;
    while (q--) {
        int l,r; cin>>l>>r;
        cout<<ans[l-1][r-1]<<endl;

    }
}