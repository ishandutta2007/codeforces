#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <iomanip>
#include <random>

using namespace std;
const int INF = 1e9;

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);
    vector <int> p(n), cur(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[y].push_back(x);
        ++p[x];
    }
    vector <int> d(n, INF);
    set <pair <int, int>> s;
    d[n - 1] = 0;
    s.insert(make_pair(0, n - 1));
    while (!s.empty()) {
        auto [w, v] = *s.begin();
        s.erase(s.begin());
        for (int i : g[v]) {
            int prv = d[i];
            if (d[i] == INF) {
                d[i] = w + p[i];
            } else {
                d[i] = min(d[i], w + p[i] - cur[i]);
            }
            ++cur[i];
            if (d[i] < prv) {
                s.erase(make_pair(prv, i));
                s.insert(make_pair(d[i], i));
            }
        }
    }
    cout << d[0];
}

/*

 */