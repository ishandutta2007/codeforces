#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const int N = 5e3 + 3;
ll mod = 1e9 + 7;

ll n,k,a,b,dp[N][N],pre[N];

int main(){
    cin>>n>>a>>b>>k;
    dp[a][0] = 1;
    for(int i = 1; i <= k; i++) {
        fill_n(pre,0,N);
        pre[1] = dp[1][i-1];
        //cout<<pre[1]<<" ";
        for(int m = 2; m <= n; m++) {
            pre[m] = (pre[m-1]%mod + dp[m][i-1]%mod)%mod;
            //cout<<pre[m]<<" ";
        }
        //cout<<endl;
        for(int j = 1; j <= n; j++){
            if(a < b){
                if(j >= b) continue;
                ll lb = 1;
                ll rb = ceil((ld)(j + b)/2);
                dp[j][i] = (pre[rb-1]%mod - pre[lb-1]%mod - dp[j][i-1]%mod)%mod;
                if(dp[j][i] < 0) dp[j][i] += mod;
                //cout<<j<<" "<<lb<<" "<<rb<<endl;
                //cout<<pre[rb-1]<<" "<<pre[lb-1]<<" "<<dp[j][i-1]<<endl;
            }
            if(a > b){
                if(j <= b) continue;
                ll rb = n;
                ll lb = (j + b)/2;
                dp[j][i] = (pre[rb]%mod - pre[lb]%mod - dp[j][i-1]%mod)%mod;
                if(dp[j][i] < 0) dp[j][i] += mod;
                //cout<<j<<" "<<lb<<" "<<rb<<endl;
            }
            //cout<<j<<" "<<i<<" "<<dp[j][i]<<endl;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[i][k] %= mod;
    cout<<(ll)ans%mod<<endl;
}