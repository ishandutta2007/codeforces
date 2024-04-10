#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pi;
struct oper {
    int f, t, k;
    oper(int _f, int _t, int _k) : f(_f), t(_t), k(_k) {}
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, all = 0;
    cin >> n >> m;
    vector<int> pos[m], sz(n), pf(n);
    vector<pi> v;
    vector<oper> ops;
    set<int> sl;
    for (int i = 0; i < n; ++i) {
        cin >> sz[i];
        v.emplace_back(sz[i], i);
        all += sz[i];
        for (int j = 0; j < sz[i]; ++j) {
            int x;
            cin >> x;
            --x;
            pos[x].push_back(i);
        }
    }
    sort(v.begin(), v.end());
    int k = all / n, cntl = n - all % n;
    for (int i = 0; i < n; ++i) {
        pf[v[i].second] = k + (i >= cntl);
        if (sz[v[i].second] < pf[v[i].second]) sl.insert(v[i].second);
    }
    for (int i = 0; i < m; ++i) {
        int l = 0, r = 0;
        vector<int> oks;
        auto it = sl.begin();
        while (r < pos[i].size()) {
            if (it == sl.end()) break;
            if (sz[pos[i][r]] <= pf[pos[i][r]]) {
                ++r;
                continue;
            }
            while (l < pos[i].size() && it != sl.end()) {
                if (pos[i][l] == *it) ++l, ++it;
                else if (pos[i][l] < *it) ++l;
                else break;
            }
            if (it != sl.end()) {
                ++sz[*it], --sz[pos[i][r]];
                ops.emplace_back(pos[i][r] + 1, *it + 1, i + 1);
                if (sz[*it] == pf[*it]) oks.push_back(*it);
                ++it;
            }
            ++r;
        }
        for (int j : oks) sl.erase(j);
    }
    cout << ops.size() << '\n';
    for (oper i : ops) cout << i.f << ' ' << i.t << ' ' << i.k << '\n';
}