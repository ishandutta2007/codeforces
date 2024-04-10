#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll half = n / 2;
    ll ans = 8 * half * (half + 1) * (2 * half + 1) / 6;
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