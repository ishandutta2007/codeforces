// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
char a[N][N];
ll dp[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m,r=0;
        cin >> n >> m;
        for(ll i= 0;i<n;i++){
            for(ll j =0;j<m;j++){
                cin >> a[i][j];
                dp[i][j]=0;
            }
        }
        for(ll i = n-1;i>=0;i--){
            for(ll j = 0;j<m;j++){
                if(a[i][j]=='*'){
                    dp[i][j]=1;
                    if(i+1<n&&j-1>=0&&j+1<m) dp[i][j]=min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]})+1;
                    r+=dp[i][j];
                }
            }
        }
        cout<<r<<'\n';
    }
}