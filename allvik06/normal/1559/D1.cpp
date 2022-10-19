#include <bits/stdc++.h>

using namespace std;

struct dsu {
    int n;
    vector<int> r, p;
    set<pair<int, int>> s;
    vector<vector<int>> all;

    dsu(int n) : n(n) {
        r.resize(n, 1);
        p.resize(n);
        all.resize(n);
        for (int i = 0; i < n; ++i) {
            all[i].push_back(i);
            p[i] = i;
            s.insert(make_pair(1, i));
        }
    }

    inline int parent(int a) {
        if (a == p[a]) return a;
        p[a] = parent(p[a]);
        return p[a];
    }

    inline void unite(int a, int b) {
        a = parent(a);
        b = parent(b);
        if (a == b) return;
        if (r[a] > r[b]) swap(a, b);
        s.erase(make_pair(r[a], a));
        s.erase(make_pair(r[b], b));
        r[b] += r[a];
        p[a] = b;
        s.insert(make_pair(r[b], b));
        while (!all[a].empty()) {
            all[b].push_back(all[a].back());
            all[a].pop_back();
        }
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> one(m1), two(m2);
    for (int i = 0; i < m1; ++i) {
        cin >> one[i].first >> one[i].second;
        --one[i].first;
        --one[i].second;
    }
    for (int i = 0; i < m2; ++i) {
        cin >> two[i].first >> two[i].second;
        --two[i].first;
        --two[i].second;
    }
    if (m1 < m2) {
        swap(m1, m2);
        one.swap(two);
    }
    dsu fir(n);
    dsu sec(n);
    for (int i = 0; i < m1; ++i) {
        fir.unite(one[i].first, one[i].second);
    }
    for (int i = 0; i < m2; ++i) {
        sec.unite(two[i].first, two[i].second);
    }
    vector<pair<int, int>> ans;
    for (int _ = 0; _ < n - 1 - m1; ++_) {
        vector <pair <int, int>> tmp;
        for (int kek = 0; kek < 2; ++kek) {
            bool ok = false;
            auto now = *fir.s.rbegin();
            auto ver = sec.s.begin()->second;
            for (int i : sec.all[ver]) {
                if (fir.parent(i) != now.second) {
                    for (int j : fir.all[now.second]) {
                        if (sec.parent(j) != i) {
                            for (auto lol : tmp) {
                                fir.s.insert(lol);
                            }
                            ok = true;
                            ans.emplace_back(i, j);
                            fir.unite(i, j);
                            sec.unite(i, j);
                            break;
                        }
                    }
                }
                if (ok) break;
            }
            if (ok) break;
            tmp.push_back(now);
            fir.s.erase(now);
        }
    }
    //  assert(m1 + (int)ans.size() == n - 1);
    cout << (int) ans.size() << "\n";
    for (auto i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
}