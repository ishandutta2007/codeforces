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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void f(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    vvi cnt(n,vi(n));
    F0(i,n) cnt[i][i+a[i]]++;
    F1(i,n-1) cnt[0][i] += cnt[0][i-1];
    F1(i,n-1) cnt[i][0] += cnt[i-1][0];
    F1(i,n-1) F1(j,n-1) cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
    vvi dp(n,vi(n+1));
    F1(i,n-1){
        REP(j,i+1,n) dp[i][j] = INF;
        F0(ip,i) {
            int jp = a[ip]+ip;
            if(jp >= i) {
                mini(dp[i][jp+1],dp[ip][i]);
            }
        }
        REP(j,i+2,n) mini(dp[i][j],dp[i][j-1]);
        REP(j,i+1,n){
            int cntij = 0;
            if(i > 0 and j > 0) cntij += cnt[i-1][j-1];
            if(i > 0) cntij -= cnt[i-1][i-1];
            dp[i][j] += cntij - 1;
        }

    }
    cout<<dp[n-1][n]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) f();
    return 0;
}