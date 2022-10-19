#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<long long> pr(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> pos;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        pr[i + 1] = pr[i] + a[i] - b[i];
        if (pr[i + 1] != 0) {
            pos.insert(i + 1);
        }
    }
    vector<int> l(m), r(m);
    vector<vector<int>> lr(n + 1);
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        l[i]--;
        lr[l[i]].push_back(i);
        lr[r[i]].push_back(i);
        if (pr[l[i]] == 0 && pr[r[i]] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int ind = q.front();
        q.pop();
        while (true) {
            auto it = pos.lower_bound(l[ind]);
            if (it == pos.end() || *it > r[ind]) {
                break;
            }
            pr[*it] = 0;
            for (auto ind2 : lr[*it]) {
                if (pr[l[ind2]] == 0 && pr[r[ind2]] == 0) {
                    q.push(ind2);
                }
            }
            pos.erase(it);
        }
    }
    if (!pos.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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