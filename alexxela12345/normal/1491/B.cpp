#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int long long

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> arr(n);
    int ans = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        if (abs(arr[i] - arr[i + 1]) >= 2) {
            ans = 0;
        }
    }
    if (*min_element(arr.begin(), arr.end()) != *max_element(arr.begin(), arr.end())) {
        ans = min(ans, min(u, v)); 
    } else {
        ans = min(ans, v + min(u, v));
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}