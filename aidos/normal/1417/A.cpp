#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, k;
int a[maxn];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans += (k - a[i])/a[0];
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}