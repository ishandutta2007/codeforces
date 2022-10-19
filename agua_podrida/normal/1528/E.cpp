#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 998244353;

const int N = 1e6;
ll g[N+1],dp[N+1];
ll inv2 = (mod+1)/2;

ll powmod(ll a, int exp){
    if(exp == 0) return 1;
    ll b = powmod(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    b %= mod;
    return b;
}

ll inv6 = powmod(6,mod-2);

void e(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<"5\n";
        return;
    }
    g[0] = 1;
    F1(i,n){
        g[i] = (g[i-1]+1)*(g[i-1]+2);
        g[i] %= mod;
        g[i] *= inv2;
        g[i] %= mod;
    }
    dp[0] = 1;
    dp[1] = 2;
    REP(i,2,n){
        dp[i] = (((g[i-1]+1) * (g[i-1]+2)) % mod);
        dp[i] -= (((g[i-2]+1) * (g[i-2]+2)) % mod);
        dp[i] %= mod;
        dp[i] *= inv2;
        dp[i] %= mod;
        if(dp[i] < 0) dp[i] += mod;
    }
    ll borde = ((g[n-1]+1) * (g[n-1]+2)) % mod * (g[n-1]+3);
    borde -= ((g[n-2]+1) * (g[n-2]+2)) % mod * (g[n-2]+3);
    borde %= mod;
    borde *= inv6;
    borde %= mod;
    ll res = 2*borde-1;
    res %= mod;
    if(res < 0) res += mod;
    F1(i,n-1) {
        if(i == n-1) res += dp[i-1]-1;
        else res += (dp[i-1]-1) * (dp[n-i] - dp[n-i-1]);
        res %= mod;
        if(res < 0) res += mod;
    }
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    e();
    return 0;
}