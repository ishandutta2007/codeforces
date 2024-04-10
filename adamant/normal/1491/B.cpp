#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    int a[n];
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            mx = max(mx, abs(a[i] - a[i - 1]));
        }
    }
    if(mx == 0) {
        cout << min(u + v, 2 * v) << "\n";
    } else if(mx == 1) {
        cout << min(u, v) << "\n";
    } else {
        cout << 0 << "\n";
    }
    
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}