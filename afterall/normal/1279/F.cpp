#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;
ll a[N];
pii dp[N];
ll par[N];
ll n,k,le;
ll solve(){
    for (int i=1;i<=n;i++){
        par[i]=par[i-1]+a[i];
    }
    ll l=-1,r=(ll)1e15;
    while(r-l>1){
        ll mid=(r+l)/2;
        for (int i=0;i<N;i++) dp[i]={0,0};
        for (int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            dp[i].F+=a[i];
            ll z=i-le;
            z=max(z,(ll)0);
            if (min(le,i)+dp[z].F-mid>dp[i].F){
                dp[i].F=min(i,le)+dp[z].F-mid;
                dp[i].S=dp[z].S+1;
            }
        }
        if (dp[n].S>k) l=mid;
        else r=mid;

    }
  //  r--;
    for (int i=0;i<N;i++) dp[i]={0,0};
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        dp[i].F+=a[i];
        ll z=i-le;
        z=max(z,(ll)0);
        if (min(le,i)+dp[z].F-r>dp[i].F){
            dp[i].F=min(i,le)+dp[z].F-r;
            dp[i].S=dp[z].S+1;
        }
    }
  //  cout << r << " " << dp[n].F << " " << dp[n].S << endl;
    return dp[n].F+r*k;
}
int32_t main(){
    cin >> n >> k >> le;
    string s;
    cin >> s;
    for (int i=1;i<=n;i++){
        if (s[i-1]>='a' && s[i-1]<='z') a[i]=1;
    }
    ll ans=solve();
    for (int i=1;i<=n;i++) a[i]=1-a[i];
    ans=max(ans,solve());
    cout << n-ans << endl;
}