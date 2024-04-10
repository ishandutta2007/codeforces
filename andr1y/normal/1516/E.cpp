// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 405;
const ll M = 1e9+7;
ll dp[N][N];
ll cdp[N][N];
ll f[N], of[N];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (a*bpm(a*a, b>>1))%M;
    else return bpm(a*a, b>>1);
}
ll c_small(ll n, ll k ){
    return (((f[n]*of[k])%M)*of[n-k])%M;
}
ll c_big(ll n, ll k){
    ll res=of[k];
    for(ll i = n;i>n-k;i--){
        res=(res*i)%M;
    }
    return res;
}
ll solve(ll n, ll k){
    ll res=0;
    for(ll i = 1;i<=k+k;i++){
        res+=(c_big(n, i)*cdp[i][k]);
        res%=M;
    }
    return res;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	f[0]=1;
	for(ll i = 1;i<N;i++) f[i]=(f[i-1]*i)%M;
	of[N-1]=bpm(f[N-1], M-2);
	for(ll i = N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M;
	assert((f[45]*of[45])%M==1);
    ll n, k;
    cin >> n >> k;
    dp[1][0]=1;
    for(ll i=2;i<=k+k;i++){
        for(ll j = 0;j<=k;j++){
            dp[i][j] = (dp[i-1][j]+(j?(i-1)*dp[i-1][j-1]:0))%M;
        }
    }
    for(ll j = 1;j<=k;j++){
        for(ll i = 1;i<=j+j;i++){
            for(ll f=0;f<=i;f++){
                cdp[i][j]+=M+((f&1)?-1:1)*((c_small(i, f)*dp[i-f][j])%M);
                cdp[i][j]%=M;
            }
        }
    }
    ll rese=1, reso=0;
    for(ll i = 1;i<=k;i++){
        if(i&1){
            reso+=solve(n, i);
            reso%=M;
            cout<<reso<<' ';
        }else{
            rese+=solve(n, i);
            rese%=M;
            cout<<rese<<' ';
        }
    }
}