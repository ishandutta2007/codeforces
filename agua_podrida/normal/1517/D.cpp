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
#define INF 1e9
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
const ll mod = 998244353;

void d(){
    int n,m,k;
    cin>>n>>m>>k;

    vvi der(n,vi(m-1)),izq(n,vi(m));
    F0(i,n){
        F0(j,m-1){
            cin>>der[i][j];
            izq[i][j+1] = der[i][j];
        }
    }

    vvi ab(n-1,vi(m)), arr(n,vi(m));
    F0(i,n-1){
        F0(j,m){
            cin>>ab[i][j];
            arr[i+1][j] = ab[i][j];
        }
    }

    if(k%2){
        F0(i,n){
            F0(j,m) cout<<"-1 ";
            cout<<'\n';
        }
        return;
    }
    k /= 2;

    vvvi dp(n,vvi(m,vi(k+1)));
    F1(l,k){
        F0(i,n){
            F0(j,m){
                dp[i][j][l] = INF;
                if(i > 0) mini(dp[i][j][l],dp[i-1][j][l-1] + arr[i][j]);
                if(i+1 < n) mini(dp[i][j][l],dp[i+1][j][l-1] + ab[i][j]);
                if(j > 0) mini(dp[i][j][l],dp[i][j-1][l-1] + izq[i][j]);
                if(j+1 < m) mini(dp[i][j][l],dp[i][j+1][l-1] + der[i][j]);
            }
        }
    }

    F0(i,n){
        F0(j,m){
            cout<<dp[i][j][k]*2<<' ';
        }
        cout<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    d();
}