#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const int mod = 1e9+7;
const int INF  = 1e9;
const double eps = 0.00000001;

ll powmod(ll a, ll exp){
    if(exp == 0) return 1;
    ll b = powmod(a,exp/2);
    b = (b*b) % mod;
    if(exp%2) b = (b*a) % mod;
    return b;
}

ll inv(ll a){
    return powmod(a,mod-2);
}

const int N = 1e6;

ll fact[N+1], invfact[N+1],pot2[N+1];

void precalc(){
    fact[0] = invfact[0] = pot2[0] = 1;
    F1(i,N) fact[i] = (fact[i-1] * (ll) i) % mod;
    F1(i,N) invfact[i] = inv(fact[i]);
    F1(i,N) pot2[i] = pot2[i-1] * 2 % mod;
}

ll comb(int n, int k){
    ll res = fact[n];
    res *= invfact[k];
    res %= mod;
    res *= invfact[n-k];
    res %= mod;
    return res;
}

void a(){
    int n,k;
    cin>>n>>k;
    if(k == 3 and n == 4){
        cout<<"-1\n";
        return;
    }

    vi par(n);
    F0(i,n) par[i] = (n-1) ^ i;
    if(k == n-1){
        par[1] = 3;
        par[3] = 1;
        par[n-1] = n-2;
        par[n-2] = n-1;
        par[0] = n-4;
        par[n-4] = 0;
    }
    else if(k != 0){
        par[n-1] = k;
        par[k] = n-1;
        par[(n-1) ^ k] = 0;
        par[0] = (n-1) ^ k;
    }
    F0(i,n){
        if(par[i] != -1){
            cout<<i<<' '<<par[i]<<'\n';
            par[par[i]] = -1;
        }
    }
}

int main(){
    precalc();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) a();
}