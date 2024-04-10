#include <bits/stdc++.h>

using namespace std;

const int R = 1 << 18;

long long sum[R * 2];

void build() {
    for (int i = R - 1; i > 0; --i) {
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
}

void change(int pos, int val) {
    for (pos += R; pos > 0; pos /= 2) {
        sum[pos] += val;
    }
}

long long get(int l, int r) {
    l += R;
    r += R;
    long long ans = 0;
    while (l < r) {
        if (l & 1) {
            ans += sum[l++];
        }
        if (r & 1) {
            ans += sum[--r];
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

vector<pair<int, int>> vals[R];

void precalc() {
    int l = 1, r = R - 1;
    vector<vector<int>> d(r + 1);
    for (int i = 1; i <= r; ++i) {
        for (int j = i * 2; j <= r; j += i) {
            d[j].push_back(i);
        }
    }
    for (int i = l; i <= r; ++i) {
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
        for (auto j : d[i]) {
            vals[j].emplace_back(i, 0);
            auto p = lower_bound(d[i].begin(), d[i].end(), j) - d[i].begin();
            vals[j].back().second += ((int)d[i].size() - p - 1);
            p = upper_bound(kek2.begin(), kek2.end(), max(j, i - j)) - kek2.begin();
            vals[j].back().second += ((int)kek2.size() - p);
            sum[i + R] += vals[j].back().second;
        }
        for (auto j : kek2) {
            vals[j].emplace_back(i, 0);
            auto p = upper_bound(kek2.begin(), kek2.end(), max(j, i - j)) - kek2.begin();
            vals[j].back().second += ((int)kek2.size() - p);
            sum[i + R] += vals[j].back().second;
        }
    }
    build();
}

vector<int> qs[R];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t = 1;
    cin >> t;
    vector<int> l(t), r(t);
    vector<long long> ans(t);
    for (int i = 0; i < t; ++i) {
        cin >> l[i] >> r[i];
        ans[i] = (r[i] - l[i] + 1) * 1LL * (r[i] - l[i]) * (r[i] - l[i] - 1) / 6;
        qs[l[i]].push_back(i);
    }
    for (int ll = 1; ll < R; ++ll) {
        for (auto i : qs[ll]) {
            ans[i] -= get(l[i], r[i] + 1);
        }
        for (auto [i, vl] : vals[ll]) {
            change(i, -vl);
        }
    }
    for (int i = 0; i < t; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}