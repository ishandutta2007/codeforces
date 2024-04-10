// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5005;
const ll M = 1e9+7;
ll a[N];
ll infl[N];
ll endss[N][N];
ll dp[N];
ll rdp[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, k, q;
    cin >> n >> k >> q;
    for(ll i = 0;i<n;i++) {
        cin >> a[i];
        endss[0][i]=1;
    }
    ll fi=1, fe=0;
    for(ll qq=1;qq<=k;qq++){
        for(ll i = 0;i<n;i++){
            endss[qq][i]=(i?endss[qq-1][i-1]:0)+(i+1<n?endss[qq-1][i+1]:0);
            if(endss[qq][i]>=M) endss[qq][i]-=M;
        }
    }
    //ll fi2=1, fe2=0;
    //for(ll i = 0;i<n;i++) dp[fe2][i]=endss[k][i];
    /*for(ll qq=0;qq<k;qq++){
        for(ll i = 0;i<n;i++){
            dp[fi2][i]=(i?dp[fe2][i-1]:0)+(i+1<n?dp[fe2][i+1]:0);
            if(dp[fi2][i]>=M) dp[fi2][i]-=M;
        }
        swap(fi2, fe2);
    }*/
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<=k;j++){
            ll tot = endss[j][i];
            ll ft = endss[k-j][i];
            ll er = (ft*tot)%M;
            dp[i]=(dp[i]+er)%M;
        }
    }
    ll res=0;
    for(ll i = 0;i<n;i++){
        infl[i]=(dp[i]*a[i])%M;
        res+=infl[i];
        if(res>=M) res-=M;
    }
    while(q--){
        ll i, x;
        cin >> i >> x;
        --i;
        res=(res+M-infl[i]);if(res>=M) res-=M;
        infl[i]=(dp[i]*x)%M;
        a[i]=x;
        res=(res+infl[i]);if(res>=M) res-=M;
        cout<<res<<'\n';
    }
}