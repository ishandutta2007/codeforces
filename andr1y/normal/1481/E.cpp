// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
ll a[N], dp[N], l[N], r[N], af[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++) cin >> a[i];
    for(ll i = n-1;i>=0;i--) l[a[i]]=i;
    for(ll i = 0;i<n;i++) r[a[i]]=i;
    for(ll i = n-1;i>=0;i--){
        af[a[i]]++;
        dp[i]=dp[i+1];
        if(i==l[a[i]]) dp[i]=max(dp[i], (r[a[i]]+1<n?dp[r[a[i]]+1]:0)+af[a[i]]);
        else dp[i]=max(dp[i], af[a[i]]);
    }
    cout<<n-dp[0];
}