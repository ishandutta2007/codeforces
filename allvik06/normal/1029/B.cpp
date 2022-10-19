#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> ans(n);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] <= a[i] * 2) {
            ans[i] = 1;
        }
    }
    int now = 1, maxx = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (ans[i] == 1) ++now;
        else now = 1;
        maxx = max(maxx, now);
    }
    cout << maxx;
}