// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+1488;
const ll M = 1e9+7;
ll dp[N][2];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    dp[3][1]=4;
    for(ll i = 4;i<N;i++){
        dp[i][0]=dp[i-1][1]+dp[i-2][1]+dp[i-2][1];
        dp[i][1]=max(dp[i][0], 4+dp[i-1][0]+dp[i-2][0]+dp[i-2][0]);
        dp[i][0]%=M;
        dp[i][1]%=M;
    }
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll v = dp[n][1];
        cout<<v<<'\n';
    }
}