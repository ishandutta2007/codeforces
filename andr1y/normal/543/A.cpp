// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 528;
ll a[N];
ll dp[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m, b, mod;
    cin >> n >> m >> b >> mod;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    dp[0][0]=1;
    for(ll i = 0;i<n;i++){
        for(ll j = 1;j<=m;j++){
            for(ll k = a[i];k<=b;k++){
                dp[j][k]+=dp[j-1][k-a[i]];
                if(dp[j][k]>=mod) dp[j][k]-=mod;
            }
        }
    }
    ll r=0;
    for(ll i = 0;i<=b;i++) r+=dp[m][i];
    r%=mod;
    cout<<r;
}