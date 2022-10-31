// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+1488;
ll dp[2][26], p[N][26];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll fi=0, fe=1;
    for(ll i = 0;i<k;i++){
        dp[fe][i] = (s[0]==i+'A'?0:1);
        p[0][i]=-1;
    }
    for(ll i = 1;i<n;i++){
        for(ll j = 0;j<k;j++){
            dp[fi][j] = n+n;
            ll of = (s[i]=='A'+j?0:1);
            for(ll e = 0;e<k;e++){
                if(j==e) continue;
                ll vk = dp[fe][e]+of;
                if(vk<dp[fi][j]){
                    dp[fi][j]=vk;
                    p[i][j]=e;
                }
            }
        }
        fi^=1, fe^=1;
    }
    ll mv=n+n, mp=-1;
    for(ll i = 0;i<k;i++){
        if(dp[fe][i]<mv){
            mv=dp[fe][i], mp=i;
        }
    }
    string rs = "";
    rs+='A'+mp;
    ll pe = p[n-1][mp];
    for(ll i = n-2;i>=0;i--){
        rs+='A'+pe;
        pe=p[i][pe];
    }
    cout<<mv<<'\n';
    reverse(begin(rs), end(rs));
    cout<<rs<<'\n';
}