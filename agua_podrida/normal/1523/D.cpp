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
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e18;
const double eps = 0.000000001;

int n,m,p;
vll a,b;
vector<string> s;
ll res = 0;

ll compress(ll a, ll set){
    int j = 0;
    ll res = 0;
    F0(i,m){
        if(set & (1ll<<i)) {
            if(a & (1ll<<i)) res += 1<<j;
            j++;
        }
    }
    return res;
}

ll decomp(ll a, ll set){
    int j = 0;
    ll res = 0;
    F0(i,m){
        if(set & (1ll<<i)){
            if(a & (1ll<<j)) res += (1ll<<i);
            j++;
        }
    }
    return res;
}

int bits(ll a){
    int res = 0;
    while(a) res += a%2, a >>= 1;
    return res;
}

void coso(int x){
    ll set = a[x];
    if(set == 0) return;
    vll dp((1<<bits(set)));
    vll dp2 = dp;
    F0(i,n) b[i] = compress(a[i],set);
    F0(i,n) dp[b[x]&b[i]]++;
    F0(m,dp.size())
        for(ll s = m; s; s = (s-1) & m)
            dp2[s] += dp[m];
    F0(m,dp.size())
        if(dp2[m]*2 >= n and bits(m) > bits(res)) res = decomp(m,set);
}

void d(){
    cin>>n>>m>>p;
    s.resize(n);
    b.resize(n);
    F0(i,n) cin>>s[i];
    a = vll(n);
    F0(i,n) F0(j,m) a[i] *= 2, a[i] += s[i][j] - '0';
    int it = 30;
    while(it--) coso((1000*rand()+rand())%n);
    F0R(i,m) {
        if((1ll<<i) & res) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    d();
    return 0;
}