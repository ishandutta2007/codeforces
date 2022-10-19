#include <bits/stdc++.h>

using namespace std;

#define int long long

struct line {
    long long k, b;

    line() {
    }

    line(int _k, int _b) {
        k = _k, b = _b;
    }
};

const int sq = 317;

vector<line> lines[sq], cht[sq];
vector<long double> points[sq];

int x[sq];

// k1 * x + b1 == k2 * x + b2
// x * (k1 - k2) == b2 - b1
// x = (b2 - b1) / (k1 - k2)

long double intersect(line a, line b) {
    return (b.b - a.b) / (long double)(a.k - b.k);
}

void add_line(int pos, line l) {
    while (cht[pos].size() > 1 && intersect(cht[pos].rbegin()[1], cht[pos].rbegin()[0]) >= intersect(cht[pos].rbegin()[1], l)) {
        cht[pos].pop_back();
    }
    cht[pos].push_back(l);
}

long long a[sq * sq];

void build(int pos) {
    cht[pos].clear();
    points[pos].clear();
    for (int i = pos * sq; i < (pos + 1) * sq; ++i) {
        add_line(pos, line(i, a[i]));
    }
    for (int i = 0; i + 1 < (int)cht[pos].size(); ++i) {
        points[pos].push_back(intersect(cht[pos][i], cht[pos][i + 1]));
    }
    // for (int i = 0; i < (int)cht[pos].size(); ++i) {
    //     cout << "!" << cht[pos][i].k << ' ' << cht[pos][i].b << '\n';
    // }
    // cout << '\n';
}

void add(int r) {
    for (int i = 0; i < r / sq; ++i) {
        x[i]++;
    }
    if (r % sq != 0) {
        for (int i = r / sq * sq; i < r; ++i) {
            a[i] += i;
        }
        build(r / sq);
    }
}

const long double eps = 1e-5;

pair<long long, int> get() {
    pair<long long, int> ans = {0, 0};
    for (int i = 0; i < sq; ++i) {
        int pos = upper_bound(points[i].begin(), points[i].end(), x[i] + eps) - points[i].begin();
        if (i == 0) {
            // cout << "!" << pos << ' ' << points[i][1] << '\n';
            // for (auto l : cht[i]) {
            //     cout << l.k << ' ' << l.b << '\n';
            // }
            // cout << '\n';
        }
        ans = max(ans, {cht[i][pos].k * 1LL * x[i] + cht[i][pos].b, cht[i][pos].k});
    }
    return ans;
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        mx = max(mx, b[i]);
    }
    vector<vector<int>> pos(mx + 2);
    for (int i = 0; i < n; ++i) {
        pos[b[i]].push_back(i);
    }
    for (int i = 0; i < sq; ++i) {
        build(i);
    }
    int cnt = n;
    for (int i = 0; i < mx + 2; ++i) {
        auto p = get();
        cout << w * 1LL * cnt * i + p.first << ' ' << p.second << '\n';
        for (auto ind : pos[i]) {
            cnt--;
            add(a[ind] + 1);
        }
    }
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