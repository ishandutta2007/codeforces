#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    long long best = 1e18;
    for (int i = 0; i < n; i++) {
        vector<int> b(n);
        long long tmp = 0;
        for (int j = i + 1; j < n; j++) {
            int foo = b[j - 1] / a[j] + 1;
            b[j] = a[j] * foo;
            tmp += foo;
        }
        for (int j = i - 1; j >= 0; j--) {
            int foo = b[j + 1] / a[j] + 1;
            b[j] = a[j] * foo;
            tmp += foo;
        }
        best = min(best, tmp);
    }
    cout << best << '\n';
    return 0;
}