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
#define todo(v) v.begin(),v.end()
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
double PI = acos(-1.0);
#define fora(e,v) for(auto e : v)
const ll mod = 998244353;
const ll INF  = 5e18;
const double eps = 0.000000001;


const int N = 100;
ll dp[N+1][N+1][N+1];
ll comb[N+1][N+1];
ll fact[N+1];
ll p;

void precalc(){
    F0(i,N+1) F0(j,N+1) F0(l,N+1) dp[i][j][l] = -1;
    fact[0] = 1;
    F1(i,N) fact[i] = fact[i-1] * (ll) i % p;
    F0(i,N+1){
        comb[i][0] = comb[i][i] = 1;
        F1(j,i-1) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % p;
    }
}

ll f(int n, int m, int k){
    if(n == 0) return 1;
    if(m > n and k != 0) return 0;
    if(m == 1){
        if(k == 1) return fact[n];
        else return 0;
    }
    if(dp[n][m][k]== -1){
        dp[n][m][k] = 0;
        F1(i,n){
            for(int k1 = max(0,k-n+i); k1 <= min(k,i-1); k1++){
                int k2 = k-k1;
                dp[n][m][k] += (f(i-1,m-1,k1) * f(n-i,m-1,k2) % p) * comb[n-1][i-1];
                dp[n][m][k] %= p;
            }
        }
    }
    return dp[n][m][k];
}

void a(){
    int n,m,k;
    cin>>n>>m>>k>>p;
    precalc();
    cout<<f(n,m,k)<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a();
    return 0;
}