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
const int N=2e5+100;
ll a[N],dp[N];
int Main(){
    ll n,p,k;
    cin >> n >> p >> k;
    for (int i=0;i<=n+10;i++) dp[i]=0,a[i]=0;
    for (int i=1;i<=n;i++){
        char c;
        cin >> c;
        a[i]=c-'0';
    }
    ll x,y;
    cin >> x >> y;
    for (int i=n;i;i--){
        if (i+k<=n) dp[i]=dp[i+k];
        if (a[i]==0) dp[i]+=x;
    }
    ll ans=(ll)1e15;
    for (int i=p;i<=n;i++){
        ans=min(ans,dp[i]+(i-p)*y);
    }
    kill(ans);


}
int32_t main(){
    sync;
    ll t;
    t=1;
    cin >> t;
    while(t--){
        Main();
    }
}