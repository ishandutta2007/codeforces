#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> cnt2;
    for (int el : arr) {
        cnt2[el]++;
    }
    map<int, int> cnt;
    for (auto &pp : cnt2) {
        cnt[pp.second]++;
    }
    int ans = n;
    for (auto pp : cnt) {
        int C = pp.first;
        int rem = 0;
        for (auto pp2 : cnt) {
            if (pp2.first < C) {
                rem += pp2.first * pp2.second;
            } else {
                rem += (pp2.first - C) * pp2.second;
            }
        }
        ans = min(ans, rem);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}