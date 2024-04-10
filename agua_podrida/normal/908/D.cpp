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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

ll pot(ll a, int exp){
    if(exp == 0) return 1;
    ll b = pot(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    b %= mod;
    return b;
}

ll inv(ll a){
    return pot(a,mod-2);
}

int k;
ll a,b;

ll f(vvll& dp, int i, int j){
    if(j >= k) return j;
    if(i+j >= k){
        ll res = (ll) i + (ll) j + (a+b)*inv(b) - 1ll;
        res %= mod;
        if(res < 0) res += mod;
        return res;
    }
    if(dp[i][j] == -1){
        if(i == 0){
            return f(dp,i+1,j);
        }
        else {
            dp[i][j] = ((f(dp,i+1,j) * a) %mod) * inv(a+b);
            dp[i][j] %= mod;
            dp[i][j] += ((f(dp,i,j+i) * b)%mod) * inv(a+b);
            dp[i][j] %= mod;
        }
    }
    return dp[i][j];
}

void d(){
    cin>>k>>a>>b;
    vvll dp(k+1,vll(k+1,-1));
    ll res = f(dp,0,0);
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}