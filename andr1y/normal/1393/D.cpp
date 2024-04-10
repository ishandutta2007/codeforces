// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2020;
char a[N][N];
ll dp[4][N][N]; //up left right down
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++){
            dp[3][i][j] = 1;
            if(i&&j&&j+1<m&&a[i-1][j-1]==a[i-1][j]&&a[i-1][j]==a[i-1][j+1]&&a[i][j]==a[i-1][j]){
                dp[3][i][j] = max(dp[3][i][j], min(dp[3][i-1][j-1], min(dp[3][i-1][j], dp[3][i-1][j+1]))+1);
            }
        }
    }
    for(ll i = n-1;i>=0;i--){
        for(ll j = 0;j<m;j++){
            dp[0][i][j] = 1;
            if(i+1<n&&j&&j+1<m&&a[i+1][j-1]==a[i+1][j]&&a[i+1][j]==a[i+1][j+1]&&a[i][j]==a[i+1][j]){
                dp[0][i][j] = max(dp[0][i][j], min(dp[0][i+1][j-1], min(dp[0][i+1][j], dp[0][i+1][j+1]))+1);
            }
        }
    }
    for(ll j = 0;j<m;j++){
        for(ll i = 0;i<n;i++){
            dp[2][i][j] = 1;
            if(j&&i&&i+1<n&&a[i-1][j-1]==a[i][j-1]&&a[i][j-1]==a[i+1][j-1]&&a[i][j-1]==a[i][j]){
                dp[2][i][j] = max(dp[2][i][j], min(dp[2][i][j-1], min(dp[2][i-1][j-1], dp[2][i+1][j-1]))+1);
            }
        }
    }
    for(ll j = m-1;j>=0;j--){
        for(ll i = 0;i<n;i++){
            dp[1][i][j] = 1;
            if(j+1<m&&i&&i+1<n&&a[i-1][j+1]==a[i][j+1]&&a[i][j+1]==a[i+1][j+1]&&a[i][j+1]==a[i][j]){
                dp[1][i][j] = max(dp[1][i][j], min(dp[1][i][j+1], min(dp[1][i-1][j+1], dp[1][i+1][j+1]))+1);
            }
        }
    }
    ll res=0;
    for(ll i = 0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll l=1, r=min(min(i+1, j+1), min(n-i, m-j))+1;
            while(r-l>1){
                ll mid = (l+r)>>1;
                bool ok = 1;
                ok&=dp[0][i-mid+1][j]>=mid;
                ok&=dp[3][i+mid-1][j]>=mid;
                ok&=dp[1][i][j-mid+1]>=mid;
                ok&=dp[2][i][j+mid-1]>=mid;
                if(ok) l =mid;
                else r=mid;
            }
            res+=l;
        }
    }
    cout<<res;
}