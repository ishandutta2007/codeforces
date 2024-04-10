#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5, maxc = 1e6 + 5;
int inf = 1e18;
int best[maxc], imax[(1 << 21)], psh[(1 << 21)];

void build(int i, int l, int r) {
    if (r - l == 1) imax[i] = best[l];
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
    }
}

inline void push(int i, int l, int r) {
    imax[i] += psh[i];
    if (r - l > 1) {
        psh[2 * i + 1] += psh[i], psh[2 * i + 2] += psh[i];
    }
    psh[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int x) {
    push(i, l, r);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i, l, r);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
    imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p, x, y, ans = -inf, z, ptr = 0;
    cin >> n >> m >> p;
    vector < pair < int, int > > a;
    vector < vector < int > > b;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        a.push_back({x, y});
    }
    for (int i = 1; i < maxc; ++i) best[i] = -inf;
    sort(a.begin(), a.end());
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        best[x] = max(best[x], -y);
    }
    build(0, 1, maxc);
    for (int i = 1; i <= p; ++i) {
        cin >> x >> y >> z;
        b.push_back({x, y, z});
    }
    sort(b.begin(), b.end());
    for (auto key : a) {
        while (ptr < (int)b.size() && b[ptr][0] < key.first) {
            update(0, 1, maxc, b[ptr][1] + 1, maxc, b[ptr][2]);
            ptr++;
        }
        ans = max(ans, -key.second + imax[0]);
    }
    cout << ans << '\n';
    return 0;
}