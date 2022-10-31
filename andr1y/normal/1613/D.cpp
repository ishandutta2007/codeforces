/*
 _  _    _  _  ____  _  _  ____    _  _  ____  ____    ____  ____   __  ____   __   ____  _  _ 
( \/ )  ( \/ )(  __)/ )( \/ _  )  / )( \(  __)(_  _)  /    \(  _ \ /  \(  __) /  \ (  __)( \/ )
 )  /   / \/ \ ) _) ) __ (\    \  ) __ ( ) _)   )(    ) /\ ( ) __/(  O )) _ \/ /\ \ ) _) / \/ \
(__/    \_)(_/(____)\_)(_/(_/__/  \_)(_/(____) (__)   \_)(_/(__)   \__/(____/\_)(_/(____)\_)(_/
 __ _  ____   __   _  _  ____    _  _   __  ____  _ u_    ____   __   _ _   __ _  _ __         
(  / )(  _ \ /  \ ( \/ )(  __)  ( \/ ) /  \(  __)/ )  )  (  __) / _\ ( ) ))(  / )/ )  )        
 )  (  ) __/(  O )/ \/ \ ) _)   / \/ \(  O )) _) \    \   ) _ \/    \/( ( \ )  ( \    \        
(__\_)(__)   \__/ \_)(_/(____)  \_)(_/ \__/(____)(__(_/  (____/\_/\_/\____/(__\_)(__(_/        
  __   __    __    __       ____                                                               
 /  \ /  \  /  \  /  \  ___(__  )                                                              
(_/ /(  0 )(  0 )(  0 )(___) / /                                                               
 (__) \__/  \__/  \__/      (_/                                                                
 ____    _  _  _  _  ____  ____    ____  ____   __    ___  ____  _ __                          
/ _  )  ( \/ )( \/ )(  __)(  _ \  /    \(  _ \ /  \  / __)(_  _)/ )  )                         
\    \   )  / / \/ \ ) _)  ) __/  ) /\ ( ) __/(  O )( (__   )(  \    \ _  _  _                 
(_/__/  (__/  \_)(_/(____)(__)    \_)(_/(__)   \__/  \___) (__) (__(_/(_)(_)(_)                

(c) 255.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+30;
const ll M = 998244353;

ll pow2[N];

ll a[N];

ll dp[3][N];
ll sdp[3][N];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    pow2[0]=1;
    for(ll i = 1;i<N;i++) pow2[i]=(pow2[i-1]*2)%M;
    ll q;
    cin >> q;
    while(q--){
        ll n,res=0;
        cin >> n;
        for(ll i = 0;i<=n+15;i++) dp[0][i]=dp[1][i]=sdp[0][i]=sdp[1][i]=dp[2][i]=sdp[2][i]=0;
        ll cnt1=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            if(a[i]==1) cnt1++;
            if(a[i]) dp[0][i] = sdp[0][a[i]-1] + sdp[0][a[i]];
            else dp[0][i] = sdp[0][0]+1;
            if(a[i]>1) dp[1][i] = sdp[0][a[i]-2] + sdp[1][a[i]] + sdp[2][a[i]-2];
            dp[2][i] = sdp[2][a[i]] + sdp[1][a[i]+2];
            dp[0][i]%=M;
            dp[1][i]%=M;
            dp[2][i]%=M;
            sdp[0][a[i]]+=dp[0][i]; sdp[0][a[i]]%=M;
            sdp[1][a[i]]+=dp[1][i]; sdp[1][a[i]]%=M;
            sdp[2][a[i]]+=dp[2][i]; sdp[2][a[i]]%=M;
            res=(res+dp[0][i]+dp[1][i]+dp[2][i])%M;
        }
        res+=pow2[cnt1]+M-1;
        res%=M;
        cout<<res<<'\n';
    }
}