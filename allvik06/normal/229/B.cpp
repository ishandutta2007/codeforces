#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e18;

signed main() {
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, int>>> a(n);
    for (int i = 0; i < m; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        a[x - 1].emplace_back(y - 1, v);
        a[y - 1].emplace_back(x - 1, v);
    }
    vector <unordered_map <int, int>> k(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) continue;
        int last;
        cin >> last;
        vector <int> tmp;
        tmp.push_back(last);
        for (int j = 1; j < x; ++j) {
            int y;
            cin >> y;
            if (y == last + 1) {
                tmp.push_back(y);
                last = y;
            }
            else {
                for (int o : tmp) {
                    k[i][o] = last + 1;
                }
                tmp.clear();
                tmp.push_back(y);
                last = y;
            }
        }
        for (int o : tmp) {
            k[i][o] = last + 1;
        }
    }
    vector <int> d(n, INF);
    set <pair <int, int>> s;
    s.insert({0, 0});
    for (int i = 1; i < n; ++i) {
        s.insert({INF, i});
    }
    while (!s.empty()) {
        pair <int, int> now = *s.begin();
        s.erase(s.begin());
        if (now.second == n - 1) {
            if (now.first == INF) cout << -1;
            else cout << now.first;
            return 0;
        }
        for (auto i : a[now.second]) {
            if (k[now.second].find(now.first) == k[now.second].end()) {
                if (d[i.first] > now.first + i.second) {
                    s.erase({d[i.first], i.first});
                    d[i.first] = now.first + i.second;
                    s.insert({d[i.first], i.first});
                }
            }
            else {
                int tmpt = k[now.second][now.first];
                if (d[i.first] > tmpt + i.second) {
                    s.erase({d[i.first], i.first});
                    d[i.first] = tmpt + i.second;
                    s.insert({d[i.first], i.first});
                }
            }
        }
    }
    cout << -1;
    return 0;
}