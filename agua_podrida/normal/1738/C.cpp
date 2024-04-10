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
const ll mod = 1e9+7;
const ll INF  = 8e18;
const int inf = 1e9;
const double eps = 0.00000001;

const int N = 100;
bool dp[N+1][N+1][2][2];
//pares,impares,paridadAlice,turno (0 alice, 1 Bob).
//true sii gana alice

void precalc(){
    F0(i,N+1) F0(j,N+1) F0(k,2) F0(l,2) dp[i][j][k][l] = false;
    F0(k,2) F0(l,2) dp[0][0][k][l] = (k == 0);
    F0(i,N+1){
        F0(j,N+1){
            if(i+j == 0) continue;
            F0(k,2){
                F0(l,2){
                    if(l == 0){
                        dp[i][j][k][l] = false;
                        if(i > 0 and dp[i-1][j][k][1]) dp[i][j][k][l] = true;
                        if(j > 0 and dp[i][j-1][(k+1)%2][1]) dp[i][j][k][l] = true;
                    }
                    else {
                        dp[i][j][k][l] = true;
                        if(i > 0 and !dp[i-1][j][k][0]) dp[i][j][k][l] = false;
                        if(j > 0 and !dp[i][j-1][k][0]) dp[i][j][k][l] = false;
                    }
                }
            }
        }
    }
}

void c(){
    int n,x;
    int pares = 0, impares = 0;
    cin>>n;
    F0(i,n) {
        cin>>x;
        if(x%2) impares++;
        else pares++;
    }
    if(dp[pares][impares][0][0]) cout<<"Alice\n";
    else cout<<"Bob\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    int t;
    cin>>t;
    while(t--) c();
}