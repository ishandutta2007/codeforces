#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int mx = -1;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s += x;
        mx = max(mx, x);
    }
    if (s > mx * (n - 1))
        cout << ((s + n - 2) / (n - 1)) * (n - 1) - s << '\n';
    else
        cout << mx * (n - 1) - s << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}