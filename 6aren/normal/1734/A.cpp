#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e: a) cin >> e;
        sort(a.begin(), a.end());
        int res = 1e9;
        for (int i = 1; i + 1 < n; i++) {
            res = min({res, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1])});
        }
        cout << res << '\n';
    }
    return 0;
}