#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 7;


signed main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    vector <bool> used(n);
    int last = INF;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        last = a[i];
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > last && !used[j]) {
                ++ans;
                used[j] = true;
                last = a[j];
            }
        }
    }
    cout << ans;
    return 0;
}