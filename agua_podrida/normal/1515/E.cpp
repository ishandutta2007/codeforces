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
#define INF 2e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
ll mod = 998244353;

const int N = 400;
ll dp[N+1][N+1];
ll pot2[N+1];

ll comb[N+1][N+1];

void precalc(){
    comb[0][0] = 1;
    F1(i,N){
        F0(j,i+1){
            if(j == 0 or j == i) comb[i][j] = 1;
            else comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
        }
    }
}

void e(){
    int n;
    cin>>n>>mod;
    precalc();
    pot2[0] = 1;
    F1(i,N) pot2[i] = (pot2[i-1]*2)%mod;

    F0(i,N+1) F0(j,N+1) dp[i][j] = 0;
    dp[1][1] = 1;
    REP(i,2,n){
        REP(k,2,i){
            F1(j,i-2) {
                int kp = k - (i - j - 1);
                if (kp <= 0) continue;
                ll sumo = dp[j][kp];
                sumo *= pot2[i - j - 2];
                sumo %= mod;
                sumo *= comb[k][kp];
                sumo %= mod;
                dp[i][k] += sumo;
                dp[i][k] %= mod;
            }
        }
        dp[i][i] += pot2[i-1];
        dp[i][i] %= mod;
    }
    ll res = 0;
    REP(k,2,n) res += dp[n][k];
    res %= mod;
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    e();
}