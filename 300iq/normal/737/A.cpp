#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

vector <int> g;
int n, k, s, t;

bool check(ll v) {
    int cur = 0;
    ll res = 0;
    for (auto go : g) {
        int dist = go - cur;
        int l = 0, r = dist + 1;
        while (l < r - 1) {
            ll m = (l + r) / 2;
            if (2 * m + (dist - m) <= v) {
                l = m;
            } else {
                r = m;
            }
        }
        if (2 * l + (dist - l) > v) {
            return 0;
        }
        res += l + 2 * (dist - l);
        cur = go;
    }
    return res <= t;
}

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin >> n >> k >> s >> t;
    vector <pair <int, int> > cv;
    for (int i = 0; i < n; i++) {
        int c, v;
        cin >> c >> v;
        cv.push_back({c, v});
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        g.push_back(x);
    }
    g.push_back(s);
    sort(g.begin(), g.end());
    ll l = -1, r = 2e9 + 7;
    while (l < r - 1) {
        ll m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    int res = 2e9;
    for (int i = 0; i < n; i++) {
        if (cv[i].second >= r) {
            res = min(res, cv[i].first);
        }
    }
    cout << (res == 2e9 ? -1 : res) << '\n';
}