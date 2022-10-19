#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<pair<int, int>> segm;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            segm.insert({0, 0});
        } else {
            if (a[segm.rbegin()->first] <= a[i]) {
                auto p = *segm.rbegin();
                segm.erase(p);
                p.second++;
                segm.insert(p);
            } else {
                segm.insert({i, i});
            }
        }
    }
    while (m--) {
        int k, d;
        cin >> k >> d;
        k--;
        a[k] -= d;
        auto it = segm.lower_bound({k + 1, 0});
        it--;
        pair<int, int> nw;
        if (it->first != k && a[it->first] > a[k]) {
            auto p = *it;
            segm.erase(it);
            segm.insert({p.first, k - 1});
            nw = {k, p.second};
        } else {
            nw = *it;
            segm.erase(it);
        }
        while (true) {
            auto it = segm.lower_bound({k + 1, 0});
            if (it == segm.end() || a[it->first] < a[k]) {
                break;
            }
            nw.second = it->second;
            segm.erase(it);
        }
        segm.insert(nw);
        cout << segm.size() << ' ';
    }
    cout << '\n';
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