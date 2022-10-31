//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], dp[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 1;i<=n;i++){
            cin >> a[i];
        }
        dp[1] = 1;
        ll mv=1;
        for(ll i = 2;i<=n;i++){
            dp[i] = 1;
            for(ll j = 1;j*j<=i;j++){
                if(i%j!=0) continue;
                if(a[i]>a[j]) dp[i]=max(dp[i], dp[j]+1);
                if(j!=1&&a[i]>a[i/j]) dp[i]=max(dp[i], dp[i/j]+1);
            }
            mv = max(mv, dp[i]);
        }
//        for(ll i=1;i<=n;i++)cout << dp[i] << ' ';
        cout << mv << '\n';
    }
}