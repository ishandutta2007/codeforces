// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll x[N], y[N], t[N], mx[N], dp[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll r, n;
    cin >> r>>n;
    memset(dp, 0xaa, sizeof(dp));
    memset(mx, 0xaa, sizeof(mx));
    for(ll i =0 ;i<n;i++){
        cin >> t[i] >> x[i] >> y[i];
        if(x[i]+y[i]-2<=t[i]) dp[i]=1;
        for(ll j = i-1;j>=0;j--){
            if(t[i]-t[j]>=r+r-2){
                dp[i]=max(dp[i], mx[j]+1);
                break;
            }
            if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j])){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
        mx[i]=max((i?mx[i-1]:0), dp[i]);
    }
    cout<<mx[n-1];
}