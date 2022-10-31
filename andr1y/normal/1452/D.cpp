// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll M = 998244353;
ll dp[N];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (a*bpm(a*a, b>>1))%M;
    else return bpm(a*a, b>>1);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    dp[1]=1;
    ll sdp0=0, sdp1=1;
    for(ll i = 2;i<=n;i++){
        if(i&1){
            dp[i]=(sdp0+1)%M;
            sdp1=(sdp1+dp[i])%M;
        }else{
            dp[i]=(sdp1);
            sdp0=(sdp0+dp[i])%M;
        }
    }
    //cerr<<dp[n]<<'\n';
    ll r = (dp[n]*bpm(bpm(2, n), M-2))%M;
    cout<<r;
}