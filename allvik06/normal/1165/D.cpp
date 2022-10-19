#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int x = a[0] * a.back();
        vector <int> b;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) b.push_back(i);
            if (x % i == 0) b.push_back(x / i);
        }
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        if (a == b) cout << x << "\n";
        else cout << -1 << "\n";
    }
}