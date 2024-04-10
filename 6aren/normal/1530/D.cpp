#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n, -1);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            int &e = a[i];
            cin >> e;
            e--;
            g[e].push_back(i);
        }
        int cnt = 0;
        vector<int> remb;
        for (int i = 0; i < n; i++) {
            if (g[i].size() > 0) {
                b[g[i][0]] = i;
                cnt++;
            } else remb.push_back(i);
        }
        vector<int> rema;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) rema.push_back(i);
        }
        if (rema.size() == 1 && rema[0] == remb[0]) {
            for (int i = 0; i < n; i++) {
                reverse(g[i].begin(), g[i].end());
            }
            fill(b.begin(), b.end(), -1);
            rema.clear();
            remb.clear();
            for (int i = 0; i < n; i++) {
                if (g[i].size() > 0) {
                    b[g[i][0]] = i;
                } else remb.push_back(i);
            }
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) rema.push_back(i);
            }
        }
        sort(rema.begin(), rema.end());
        sort(remb.rbegin(), remb.rend());
        vector<pair<int, int>> foo;
        for (int i = 0; i < rema.size(); i++) foo.push_back({rema[i], remb[i]});
        sort(foo.begin(), foo.end(), [](auto lhs, auto rhs) {
            return abs(lhs.first - lhs.second) < abs(rhs.first - rhs.second);
        });
        if (foo.size() > 0) {
            if (foo[0].first == foo[0].second) {
                swap(foo[0].first, foo[1].first);
            }
            for (auto e : foo) {
                b[e.first] = e.second; 
            }
        }

        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            cout << b[i] + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}