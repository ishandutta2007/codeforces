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

const int iinf = 1<<29;
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

const int maxn = 2e5+5;

ll dp[maxn][10];

signed main(){
    IOS();
    int n; cin>>n;

    for (int j = 0; j<maxn; ++j) for (int i = 0; i<10; ++i) dp[j][i] = -1000000000000000ll;
    dp[0][0] = 0;
    for (int i = 0; i<n; ++i) {
        int k; cin>>k;
        array<vector<ll>,3> a;
        for (int j = 0; j<k; ++j) {
            int c,d; cin>>c>>d; --c; a[c].pb(d);
        }
        for (int j = 0; j<3; ++j) sort(ALL(a[j]), greater<ll>());
        for (int t = 0; t<10; ++t) {
            MX(dp[i+1][t], dp[i][t]);
            if (SZ(a[0])) {// 1-1-1
                ll sig = dp[i][t];
                for (int ntk = 0; ntk<min(3ll,SZ(a[0])); ++ntk) {
                    sig += a[0][ntk];
                    if (t + ntk +1 >= 10) {
                        MX(dp[i+1][(t+ntk+1)%10], sig + a[0][0]);
                    }else{
                        MX(dp[i+1][t+ntk+1], sig);
                    }
                }
            }
            if (SZ(a[1])){
                int sig = dp[i][t] + a[1][0];

                if (t + 1 >= 10) {
                    MX(dp[i+1][t+1-10], sig + a[1][0]);
                }else{
                    MX(dp[i+1][t+1], sig);
                }

                if (SZ(a[0])) sig += a[0][0];
                if (SZ(a[0])) if (t + 2 >= 10) {
                    MX(dp[i+1][t+2-10], sig + max(a[1][0], a[0][0]));
                }else{
                    MX(dp[i+1][t+2], sig);
                }
            }
            if (SZ(a[2])){
                int sig = dp[i][t] + a[2][0];

                if (t + 1 >= 10) {
                    MX(dp[i+1][t+1-10], sig + a[2][0]);
                }else{
                    MX(dp[i+1][t+1], sig);
                }
            }
        }
    }

    cout<<*max_element(dp[n], dp[n]+10)<<endl;
}