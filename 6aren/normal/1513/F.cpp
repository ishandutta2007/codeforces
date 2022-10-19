#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) ans += abs(a[i] - b[i]);

    auto solve = [](const vector<int> &a, const vector<int> &b) {
        int64_t res = 0;
        int n = a.size();
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) p[i] = {a[i], b[i]};
        sort(p.begin(), p.end());
        set<pair<int, int>> l, r;
        for (int i = 0; i < n; i++) l.insert({a[i], i}), r.insert({b[i], i});
        for (int i = 0; i < n; i++) {
            if (p[i].first <= p[i].second) continue;
            while (!r.empty() && r.begin()->first < p[i].first) {
                int id = r.begin()->second;
                r.erase({b[id], id});
                l.erase({a[id], id});
            }
            if (!r.empty()) {
                int foo = l.begin()->first;
                res = max(res, (int64_t) min(p[i].first - foo, p[i].first - p[i].second));
            }
        }
        return res * 2;
    };

    cout << ans - max(solve(a, b), solve(b, a)) << '\n';

    return 0;
}