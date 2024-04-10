#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

struct point {
    int x, y;
};

inline int dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

inline bool col(const point &a, const point &b) {
    return double(a.x) * b.x + double(a.y) * b.y < 0;
}
inline bool rot(const point &a, const point &b) {
    return double(a.x) * b.y > double(a.y) * b.x;
}

inline int cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

const int maxn = 1e6 + 42;

int sz = 0;
point hull[maxn], vecs[maxn];

void add_line(int k, int b) {
    point nw = {k, b};
    while(sz >= 2 && col(vecs[sz - 2], {nw.x - hull[sz - 1].x, nw.y - hull[sz - 1].y})) {
        sz--;
    }
    if(sz >= 1) {
        vecs[sz - 1] = {hull[sz - 1].y - nw.y, nw.x - hull[sz - 1].x};
    }
    hull[sz++] = nw;
}

int get(int x) {
    point query = {x, 1};
    auto it = lower_bound(vecs, vecs + sz - 1, query, [](point a, point b) {
        return rot(a, b);
    });
    return dot(query, hull[it - vecs]);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n], y[n], a[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> a[i];
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int a, int b){return x[a] < x[b];});
    int d[n];
    int ans = 0;
    add_line(0, 0);
    for(int i = 0; i < n; i++) {
        // d[i] = max(d[j] - x[j] * y[i])) + y[i] * x[i] - a[i]
        d[i] = -get(y[p[i]]) + y[p[i]] * x[p[i]] - a[p[i]];
        add_line(x[p[i]], -d[i]);
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}