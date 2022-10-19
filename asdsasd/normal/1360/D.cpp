#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    if(k >= n){
        cout << 1 << endl;
        return;
    }
    ll ans = n;
    for(ll i = 2; i * i <= n && i <= k; i++){
        if(n % i == 0){
            ans = min(ans, n / i);
            if (n / i <= k){
                ans = min(ans, i);
            }
        }
    }
    cout << ans << endl;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}