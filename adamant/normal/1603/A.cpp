#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int a[n];
    bool ans = true;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 2; j <= 50; j++) {
            if(a[i] % j != 0) {
                if(j > i + 2) {
                    ans = false;
                }
                break;
            }
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
    
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
    return 0;
}