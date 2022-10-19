//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        bool bad = 0;
        for (int j = 0; j < n; j++) {
            int kk = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
            if (kk > k)
                bad = 1;
        }
        if (!bad) {
            ans = 1;
            break;
        }

    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
}