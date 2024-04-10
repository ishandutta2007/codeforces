// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2222;
ll a[N], dp[N][N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin>> n;
    ll h1=0;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        if(a[i]==1){
            h1++;
        }
    }
    ll mv = LLONG_MAX;
    if(h1) mv=n-h1;
    for(ll i = 0;i<n;i++){
        dp[i][1] = a[i];
        for(ll j = 2;j<=i+1;j++){
            dp[i][j] = __gcd(dp[i-1][j-1], a[i]);
            if(dp[i][j]==1) mv=min(mv, j-1+n-1);
        }
    }
    if(mv==LLONG_MAX) mv=-1;
    cout<<mv<<'\n';
}