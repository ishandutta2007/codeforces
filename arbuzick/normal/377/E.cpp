#include <bits/stdc++.h>

using namespace std;

struct line {
    long long k, b;

    line(long long _k, long long _b) {
        k = _k, b = _b;
    }
};

vector<line> cht;
vector<long double> points;

long double intersect(line a, line b) {
    return (b.b - a.b) / (long double)(a.k - b.k);
}

void add_line(line l) {
    while (cht.size() > 1 && points.back() >= intersect(cht.rbegin()[1], l)) {
        cht.pop_back();
        points.pop_back();
    }
    cht.push_back(l);
    if (cht.size() > 1) {
        points.push_back(intersect(cht.rbegin()[1], cht.rbegin()[0]));
    }
}

const long double eps = 1e-7;

void solve() {
    int n;
    long long s;
    cin >> n >> s;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), [&](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    vector<pair<int, int>> p_nw;
    for (int i = 0; i < n; ++i) {
        while (!p_nw.empty() && p_nw.back().second >= p[i].second) {
            p_nw.pop_back();
        }
        p_nw.push_back(p[i]);
    }
    p = p_nw;
    add_line({p[0].first, 0});
    for (int i = 1; i < (int)p.size(); ++i) {
        int l = 0, r = p[i].second;
        while (l < r - 1) {
            int m = (l + r) / 2;
            int pos = upper_bound(points.begin(), points.end(), m + eps) - points.begin();
            if (cht[pos].k * 1LL * m + cht[pos].b >= p[i].second) {
                r = m;
            } else {
                l = m;
            }
        }
        int pos = upper_bound(points.begin(), points.end(), r + eps) - points.begin();
        long long val = cht[pos].k * 1LL * r + cht[pos].b - p[i].second;
        // k * x + b = val
        // b = val - k * x
        add_line({p[i].first, val - p[i].first * 1LL * r});
    }
    long long l = 0, r = s;
    while (l < r - 1) {
        long long m = (l + r) / 2;
        int pos = upper_bound(points.begin(), points.end(), m + eps) - points.begin();
        __int128_t nw = cht[pos].k;
        nw *= m;
        nw += cht[pos].b;
        if (nw >= s) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}