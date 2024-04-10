//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+228;
ll dp[3*N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for(ll i = b;i<=c;i++){
        dp[i+a]++;
        dp[i+b+1]--;
    }
    for(ll i = 1;i<=3*d;i++) dp[i]+=dp[i-1];
    for(ll i = 1;i<=3*d;i++) dp[i]+=dp[i-1];
    ll r = 0;
    for(ll i = c;i<=d;i++){
        r+=dp[3*d]-dp[i];
    }
    cout << r << '\n';
}