#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 1e5 + 42;
const int inf = 1e16;


void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int to_right[n];
    // a[i] = right[i] - left[i]
    if(a[0] < 0) {
        cout << "No\n";
        return;
    }
    partial_sum(a, a + n, to_right);
    for(int i = 0; i < n; i++) {
        int to_left = to_right[i] - a[i];
        if(to_left < 0 || to_right[i] < 0) {
            cout << "No\n";
            return;
        }
        if(i == n - 1 && to_right[i] > 0) {
            cout << "No\n";
            return;
        }
        if(i == 0 && to_left > 0) {
            cout << "No\n";
            return;
        }
        if(i > 0 && (to_right[i] > 0 || to_left > 0) && to_right[i - 1] == 0) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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