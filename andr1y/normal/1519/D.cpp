// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5005;
ll a[N], b[N], dp[N][N], pf[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    for(ll i = 0;i<n;i++){
        cin >> b[i];
        dp[i][i]=a[i]*b[i];
        if(i) dp[i-1][i]=a[i-1]*b[i]+a[i]*b[i-1];
        pf[i]=(a[i]*b[i])+(i?pf[i-1]:0);
    }
    for(ll L = 3;L<=n;L++){
        for(ll i = 0;i+L-1<n;i++){
            dp[i][i+L-1] = dp[i+1][i+L-2]+a[i]*b[i+L-1]+a[i+L-1]*b[i];
        }
    }
    ll res=0;
    for(ll i=0;i<n;i++){
        for(ll j =i;j<n;j++){
            res=max(res, pf[n-1]-(pf[j]-(i?pf[i-1]:0))+dp[i][j]);
        }
    }
    cout<<res;
}