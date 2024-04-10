// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+228;
const ll M = 998244353;
ll dp[N];
ll sdp[N];
ll lp[N], dc[N], lpc[N], prm[N], prc=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(ll i = 2;i<N;i++){
        if(!lp[i]){
            lp[i]=i;
            dc[i]=2, lpc[i]=1;
            prm[prc++]=i;
        }
        for(ll j = 0;j<prc&&lp[i]>=prm[j]&&i*prm[j]<N;j++){
            if(prm[j]==lp[i]){
                ll e = i*prm[j];
                lp[e]=prm[j];
                lpc[e]=lpc[i]+1;
                dc[e]=(dc[i]/(lpc[i]+1))*(lpc[e]+1);
            }else{
                lp[i*prm[j]]=prm[j];
                dc[i*prm[j]]=dc[i]*2;
                lpc[i*prm[j]]=1;
            }
        }
    }
    ll n;cin>>n;
    dp[2]=1;
    sdp[2]=1;
    for(ll i = 4;i<=n+n;i+=2){
        ll gg = i/2;
        dp[i]=(sdp[i-2]+dc[gg])%M;
        sdp[i]=(sdp[i-2]+dp[i])%M;
    }
    cout<<dp[n+n];
}