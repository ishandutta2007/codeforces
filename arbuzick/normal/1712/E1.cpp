#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<vector<int>> d(r + 1);
    for (int i = 1; i <= r; ++i) {
        for (int j = i * 2; j <= r; j += i) {
            d[j].push_back(i);
        }
    }
    long long ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += (1 + (i - l - 1)) * 1LL * (i - l - 1) / 2;
        int cnt = 0;
        for (auto j : d[i]) {
            if (j >= l) {
                ans -= cnt;
                cnt++;
            }
        }
        vector<int> kek, kek2;
        for (auto j : d[i]) {
            if (j >= l) {
                kek.push_back(j);
            }
            if (j * 2 >= l && j * 2 < i && i % (j * 2) != 0) {
                kek.push_back(j * 2);
                kek2.push_back(j * 2);
            }
        }
        sort(kek.begin(), kek.end());
        int ll = kek.size(), rr = 0;
        for (auto j : kek2) {
            while (ll > 0 && kek[ll - 1] + j > i) {
                ll--;
            }
            while (rr < kek.size() && kek[rr] < j) {
                rr++;
            }
            if (rr >= ll) {
                ans -= rr - ll;
            }
        }
        int l1 = 0, l2 = kek.size();
        for (auto j : kek2) {
            while (l1 < kek.size() && kek[l1] <= j) {
                l1++;
            }
            while (l2 > 0 && kek[l2 - 1] + j > i) {
                l2--;
            }
            ans -= (kek.size() - max(l1, l2));
        }
        l1 = 0, l2 = kek2.size();
        for (auto j : kek2) {
            while (l1 < kek2.size() && kek2[l1] <= j) {
                l1++;
            }
            while (l2 > 0 && kek2[l2 - 1] + j > i) {
                l2--;
            }
            ans += (kek2.size() - max(l1, l2));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}