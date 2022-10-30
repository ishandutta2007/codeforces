// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll dp[N], in[N], a[N], ac=0;
ll lf[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll on;
    cin >> on;
    for(ll i = 0;i<on;i++) cin >> in[i];
    ll n = 1;
    for(ll i = 0;i<on;i++){
        if(i&&in[i]==in[i-1]) continue;
        a[n++]=in[i];
    }
    ll res=n-1;
    for(ll i = 1;i<n;i++){
        dp[i]=(i<3?i:dp[i-1]+(a[i]==a[i-2]?0:1));
        if(lf[a[i]]){
            dp[i]=min(dp[i], dp[lf[a[i]]+1]+(i-lf[a[i]]-2));
        }
        lf[a[i]]=i;
        res=min(res, dp[i]+n-1-i);
    }
    cout<<res;
}