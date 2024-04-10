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


const int maxn = 1e6+5;

ll dp[maxn][2]; // DP of this subtree, taking even/odd number of nodes
vector<int> g[maxn];
void dfs(int v) {
    dp[v][0] = 0; dp[v][1] = 1;
//    vector<int> ps(SZ(g[v])+1);
//    int it = 0;
    for (int u : g[v]) {
        dfs(u);
//        ps[it++] = dp[u][0] + dp[u][1] -1;
    }
//    while (it) --it, ps[it] += ps[it+1];
    ll bonus = 0;
    ll d11 = 0, d01 = 1;
    ll d0 = 1;
    for (int u : g[v]) {
        int t0 = dp[v][0], t1 = dp[v][1];
        dp[v][0] = (t0 * dp[u][0] + t1 * dp[u][1])%mod;
        dp[v][1] = (t1 * dp[u][0] + t0 * dp[u][1])%mod;
//        (bonus += dp[v][1] * ps[it+1])%=mod;
        ll tmp = d11;
        (d11 += d01 * dp[u][1])%=mod;
        (d01 += tmp * dp[u][1])%=mod;
        (d0 *= dp[u][0])%=mod;
//        ++it;
    }
    bug(d11);
    dp[v][1] += dp[v][1] - d0; dp[v][1] %= mod; if (dp[v][1] < 0) dp[v][1] += mod;
    dp[v][0] += dp[v][0] - d11; dp[v][0] %= mod; if (dp[v][0] < 0) dp[v][0] += mod;
    ++dp[v][0]; dp[v][0] %= mod;
    bug(v, dp[v][1], dp[v][0]);
}

signed main(){
    IOS();
    int n; cin>>n;
    for (int i =1 ; i<n; ++i) {
        int p; cin>>p; --p;
        g[p].pb(i);
    }
    dfs(0);
    cout<<(dp[0][1] + dp[0][0] - 1 + mod) % mod<<endl;

}