#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n;
int a[maxn];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    long long ans = -1e18;
    for(int i = 1; i < n; i++) {
        ans = max(ans, a[i] * 1ll * a[i-1]);
    }
    cout << ans << "\n";
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}