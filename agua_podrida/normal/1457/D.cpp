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
int n,k;

int aux(vi& a, int c){
    int res = 0;
    int l = 0;
    while(l < n){
        if(a[l] == c) l++;
        else {
            res++;
            l += k;
        }
    }
    return res;
}

void b(){
    cin>>n>>k;
    vi a(n);
    F0(i,n) cin>>a[i];
    int res = n;
    F1(c,100){
        mini(res,aux(a,c));
    }
    cout<<res<<'\n';
}

void c(){
    int p;
    cin>>n>>p>>k;
    string a;
    cin>>a;
    ll x,y;
    cin>>x>>y;
    vll dp(n+k);
    F0R(i,n){
        if(i == p-2) break;
        if(a[i] == '1') {
            dp[i] = dp[i+k];
        }
        else {
            dp[i] = x + dp[i+k];
        }
    }
    ll res = INF;
    REP(i,p-1,n-1) mini(res,dp[i] + y * (ll) (i - p + 1));
    cout<<res<<'\n';
}

map<pi,int> dp;

int solve(vi& a, int n, int j){
    if(j == -1 or n == 2)
        return INF;
    if(dp.count({n,j}))
        return dp[{n,j}];
    int cnt = 0;
    F0(i,n) if(a[i] & (1<<j)) cnt++;
    if(cnt == 0) dp[{n,j}] = solve(a,n,j-1);
    else if(cnt == 1) dp[{n,j}] = solve(a,n-1,j-1);
    else if(cnt == 2) {
        int y = a[n-1];
        int x = a[n-2];
        int i = n-3;
        while(i >= 0 and x <= y) {
            x = x ^ a[i];
            i--;
        }
        dp[{n,j}] = INF;
        if(x > y) dp[{n,j}] = n-3-i;

        if(n >= 3 and a[n-3] > (a[n-2] ^ a[n-1])) mini(dp[{n,j}],1);
        else {
            a[n-2] = a[n-2] ^ a[n-1];
            mini(dp[{n,j}],1+solve(a,n-1,j-1));
            mini(dp[{n,j}],solve(a,n-2,j-1));
        }
    }
    else dp[{n,j}] = 1;

    return dp[{n,j}];
}

bool hay3(vi& a, int n, int j){
    if(j == -1)
        return false;
    int cnt = 0;
    F0(i,n) if(a[i] & (1<<j)) cnt++;
    if(cnt >= 3) return true;
    return hay3(a,n-cnt,j-1);
}

void d(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    if(hay3(a,n,29)) {
        cout<<1<<'\n';
        return;
    }
    int res = n+1;
    F0(l,n){
        REP(m,l+1,n-1){
            REP(r,m+1,n){
                int x = 0;
                REP(i,l,m-1) x = x ^ a[i];
                int y = 0;
                REP(i,m,r-1) y = y ^ a[i];
                if(x > y) mini(res,r-l-2);
            }
        }
    }
    if(res == n+1) res = -1;
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    d();
    return 0;
}