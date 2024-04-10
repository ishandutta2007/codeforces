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
#define eps 0.000000001
#define PI acos(-1.0)

void h(){
    int n;
    cin>>n;
    vll a(n);
    F0(i,n) cin>>a[i];
    vpll dp(n),dpr(n);
    dp[0] = {0,a[0]};
    F1(i,n-1){
        dp[i].second = max(a[i],dp[i-1].second+1);
        dp[i].first = dp[i-1].first + max(0ll,dp[i-1].second+1-a[i]);
    }
    reverse(todo(a));
    dpr[0] = {0,a[0]};
    F1(i,n-1){
        dpr[i].second = max(a[i],dpr[i-1].second+1);
        dpr[i].first = dpr[i-1].first + max(0ll,dpr[i-1].second+1-a[i]);
    }
    ll res = INF;
    F0(i,n-1){
        if(dp[i].second != dpr[n-i-2].second) mini(res,dp[i].first + dpr[n-i-2].first);
        else mini(res,dp[i].first + dpr[n-i-2].first+1);
    }
    mini(res,dp[n-1].first);
    mini(res,dpr[n-1].first);
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../evolution/evolution-11-common-endings.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    h();
    return 0;
}