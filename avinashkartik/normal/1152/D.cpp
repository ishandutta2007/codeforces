#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
    int q,n,m,x;
    cin>>n;
    ll mod = 1e9 + 7;
    int dp[2003][2003];
    dp[0][0] = 1;
    
    for(int i = 0; i < (2*n); i++){
        for(int j = 0; j <= i; j++){
            //cout<<dp[i][j]<<" ";
            if(j+1 <= n)
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j])%mod;
            if(j != 0)
                dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%mod;
        }
        //cout<<endl;
    }
    
    ll ans = 0;
    
    for(int i = 1; i < 2*n; i += 2)
        for(int j = 0; j <= min(2*i,2*n-i); j++)
            ans = (ans + dp[i][j])%mod;
    
    cout<<ans<<endl;
}