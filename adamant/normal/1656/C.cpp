#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(!count(a, a + n, 1)) {
        cout << "YES" << "\n";
    } else {
        sort(a, a + n);
        for(int i = 0; i + 1 < n; i++) {
            if(a[i] + 1 == a[i + 1]) {
                cout << "NO" << "\n";
                return;
            }
        }
        cout << "YES" << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}