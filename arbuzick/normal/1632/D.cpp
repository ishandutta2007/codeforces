#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ans++;
            dq.clear();
            cout << ans << ' ';
            continue;
        }
        while (!dq.empty() && gcd(dq.front(), a[i]) == 1) {
            dq.pop_front();
        }
        for (int pos = (int)dq.size() - 1; pos >= 0 && gcd(dq[pos], a[i]) != dq[pos]; --pos) {
            dq[pos] = gcd(dq[pos], a[i]);
        }
        int l = -1, r = dq.size();
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (dq[m] >= (int)dq.size() - m + 1) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r != dq.size() && dq[r] == (int)dq.size() - r + 1) {
            ans++;
            dq.clear();
        } else {
            dq.push_back(a[i]);
        }
        cout << ans << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}