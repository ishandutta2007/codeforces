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
#define mod 1000000007

ll gcd(ll a, ll b){
    if(b) return gcd(b,a%b);
    return a;
}

void a(){
    int n,m;
    cin>>n>>m;
    vll a(n),b(m);
    F0(i,n) cin>>a[i];
    F0(i,m) cin>>b[i];
    F1(i,n-1) a[i] = abs(a[0]-a[i]);

    ll g = 0;
    F1(i,n-1) g = gcd(g,a[i]);
    vll res(m);
    F0(i,m) res[i] = gcd(b[i]+a[0],g);

    for(auto r : res) cout<<r<<' ';
    cout<<'\n';
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    F0(i,n) cin>>a[i]>>b[i];
    F0(i,n) a[i] *= 2;
    F0(i,n) b[i] *= 2;
    vvi dp(n+1,vi(200*n+1,-INF));
    dp[0][0] = 0;
    int i = 0;
    while(i < n){
        F0R(j,n+1) {
            F0R(c,200*n+1){
                dp[j][c] += b[i]/2;
                if(j == 0) continue;
                int cp = c - a[i];
                if(cp >= 0) maxi(dp[j][c],dp[j-1][cp] + b[i]);
            }
        }
        i++;
    }

    F1(j,n){
        int res = 0;
        F0(c,200*n+1) maxi(res,min(dp[j][c],c));
        double r = res;
        r /= 2.0;
        cout<<setprecision(1)<<fixed<<r<<' ';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}