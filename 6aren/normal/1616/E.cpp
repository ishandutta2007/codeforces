#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string fooz = s;
    sort(fooz.begin(), fooz.end());
    if (fooz >= t) return cout << "-1\n", 0;
    s = " " + s;
    t = " " + t;
    vector<vector<int>> pos(26);
    for (int i = 1; i <= n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        reverse(pos[i].begin(), pos[i].end());
    }

    vector<int> bit(n + 1);
    
    auto update = [&](int k) {
        for (int i = k; i <= n; i += (i & (-i))) {
            bit[i]++;
        }
    };

    auto get = [&](int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    };

    long long best = 1e18;
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        int c = t[i] - 'a';
        // try to move to smaller
        for (int j = c - 1; j >= 0; j--) {
            if (pos[j].empty()) continue;
            int u = pos[j].back() - get(pos[j].back()) - 1;
            best = min(best, cur + u);
        }
        if (pos[c].empty()) break;
        int u = pos[c].back() - get(pos[c].back()) - 1;
        cur += u;
        update(pos[c].back());
        pos[c].pop_back();
        if (cur > best) break;
    }
    cout << best << '\n';
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}