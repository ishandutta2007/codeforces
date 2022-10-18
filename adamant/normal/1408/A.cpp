#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int p[n];
    p[0] = a[0];
    for(int i = 1; i < n - 1; i++) {
        if(a[i] != p[i - 1]) {
            p[i] = a[i];
        } else {
            p[i] = b[i];
        }
    }
    if(a[n - 1] != p[0] && a[n - 1] != p[n - 2]) {
        p[n - 1] = a[n - 1];
    } else if(b[n - 1] != p[0] && b[n - 1] != p[n - 2]) {
        p[n - 1] = b[n - 1];
    } else {
        p[n - 1] = c[n - 1];
    }
    for(int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << "\n";
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