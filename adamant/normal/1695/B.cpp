#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;
const int inf = 1e16;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n % 2 == 1) {
        cout << "Mike\n";
    } else {
        int mx[2] = {(int)1e16, (int)1e16};
        for(int i = 0; i < n; i++) {
            mx[i % 2] = min(mx[i % 2], a[i] * n + i);
        }
        cout << (mx[0] > mx[1] ? "Mike" : "Joe") << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}