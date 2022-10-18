#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 3e5 + 42;

vector<pair<int, int>> get_sol(int n) {
    vector<vector<int>> sets;
    for(int i = 1; i <= n; i++) {
        sets.push_back({i});
    }
    vector<pair<int, int>> res;
    while(sets.size() > 2) {
        bool rep = false;
        vector<vector<int>> nsets = {sets[0]};
        for(size_t i = 1; i < sets.size(); i++) {
            if(sets[i].size() == nsets.back().size()) {
                for(size_t j = 0; j < sets[i].size(); j++) {
                    res.emplace_back(sets[i][j], nsets.back()[j]);
                    nsets.back().push_back(sets[i][j]);
                }
                if(i + 1 < sets.size()) {
                    nsets.push_back(sets[i + 1]);
                }
                i += 1;
                rep = true;
            } else {
                nsets.push_back(sets[i]);
            }
        }
        sets = nsets;
        sort(begin(sets), end(sets), [](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
        if(!rep && sets.size() > 2) {
            size_t sz = sets[0].size();
            for(size_t j = 0; j < sz; j++) {
                res.emplace_back(sets[0][j], sets.back().back());
                sets[0].push_back(sets.back().back());
                sets.back().pop_back();
            }
            sort(begin(sets), end(sets), [](const auto &a, const auto &b) {
                return a.size() < b.size();
            });
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    auto sol = get_sol(n);
    cout << sol.size() << "\n";
    for(auto it: sol) {
        cout << it.first << ' ' << it.second << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}