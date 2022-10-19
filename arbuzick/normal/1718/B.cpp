#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> c(k);
    int mx = 0;
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        mx = max(mx, c[i]);
        sum += c[i];
    }
    vector<int> f = {1, 1};
    int sz = 2;
    while (f.back() < mx) {
        f.push_back(f[sz - 2] + f[sz - 1]);
        sz++;
    }
    int pos = -1;
    long long sum_nw = 0;
    for (int i = 0; i < sz; ++i) {
        sum_nw += f[i];
        if (sum_nw == sum) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "NO\n";
        return;
    }
    multiset<pair<int, int>> s;
    vector<int> cnt(sz);
    vector<int> a(k), b(k);
    vector<int> ind;
    int cnt0 = 0;
    for (int i = 0; i < k; ++i) {
        int x = c[i];
        for (int j = sz - 1; j > 1; --j) {
            if (x >= f[j]) {
                x -= f[j];
                cnt[j]++;
            }
        }
        if (x) {
            cnt0++;
        } else {
            x = c[i] - 1;
            for (int j = sz - 1; j > 1; --j) {
                if (x >= f[j]) {
                    x -= f[j];
                }
            }
            if (!x) {
                ind.push_back(i);
                int val1 = 0, val2 = 0;
                int x1 = c[i], x2 = c[i] - 1;
                for (int j = sz - 1; j > 1; --j) {
                    if (x1 >= f[j] && x2 >= f[j]) {
                        x1 -= f[j];
                        x2 -= f[j];
                    } else if (x1 >= f[j]) {
                        val1 += f[j];
                        x1 -= f[j];
                    } else if (x2 >= f[j]) {
                        val2 += f[j];
                        x2 -= f[j];
                    }
                }
                a[i] = val1, b[i] = val2;
                s.insert({val1, val2});
            }
        }
    }
    if (cnt0 > 2) {
        cout << "NO\n";
        return;
    }
    if (cnt0 == 1 && sum == 1) {
        cout << "YES\n";
        return;
    }
    if (cnt0 == 2 && sum == 2) {
        cout << "YES\n";
        return;
    }
    for (int i = 2; i <= pos; ++i) {
        if (cnt[i] != 1) {
            break;
        }
        if (i == pos && cnt0 == 2) {
            cout << "YES\n";
            return;
        }
    }
    for (auto i : ind) {
        bool ch = true;
        int val1 = 0, val2 = 0;
        int x1 = c[i], x2 = c[i] - 1;
        for (int j = sz - 1; j > 1; --j) {
            if (x1 >= f[j]) {
                x1 -= f[j];
                cnt[j]--;
            }
            if (x2 >= f[j]) {
                x2 -= f[j];
                cnt[j]++;
            }
        }
        for (int j = pos; j > 1; --j) {
            if (cnt[j] > 2) {
                ch = false;
                break;
            }
            if (cnt[j] == 0) {
                val2 += f[j];
            }
            if (cnt[j] == 2) {
                val1 += f[j];
            }
        }
        if (ch) {
            if (val1 == 0 && val2 == 0 && cnt0 == 1) {
                cout << "YES\n";
                return;
            }
            if (cnt0 == 0) {
                s.erase(s.find({a[i], b[i]}));
                if (s.find({val1, val2}) != s.end()) {
                    cout << "YES\n";
                    return;
                }
                s.insert({a[i], b[i]});
            }
        }
        x1 = c[i], x2 = c[i] - 1;
        for (int j = sz - 1; j > 1; --j) {
            if (x1 >= f[j]) {
                x1 -= f[j];
                cnt[j]++;
            }
            if (x2 >= f[j]) {
                x2 -= f[j];
                cnt[j]--;
            }
        }
    }
    cout << "NO\n";
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