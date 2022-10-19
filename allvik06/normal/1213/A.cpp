#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, ans = 0;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) % 2 == 0) {
            ++ans;
        }
    }
    if (ans > n - ans) {
        cout << n - ans;
    }
    else {
        cout << ans;
    }
}