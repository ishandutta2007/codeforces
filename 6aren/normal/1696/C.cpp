#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = [&](vector<int> x, int m) {
        vector<pair<int, int>> res;
        for (int e : x) {
            int u = e;
            while (u % m == 0) {
                u /= m;
            }
            res.emplace_back(u, e / u);
        }
        vector<pair<int, int>> ans;
        for (int l = 0, r = 0; l < res.size(); l = r) {
            while (r < res.size() && res[r].first == res[l].first) {
                r++;
            }
            int sum = 0;
            for (int i = l; i < r; i++) {
                sum += res[i].second;
            }
            ans.emplace_back(res[l].first, sum);
        }
        return ans;
    };

    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
        }
        int k;
        cin >> k;
        vector<int> b(k);
        for (int &e : b) {
            cin >> e;
        }
        if (solve(a, m) == solve(b, m)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}