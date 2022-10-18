#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5 + 42;

using tab = array<array<int, 3>, 3>;

tab mx[4 * maxn];
array<int, 3> pi;

tab concat(tab const& a, tab const& b) {
    tab res = {};
    for(int zlr = 0; zlr < 3; zlr++)
    for(int zrl = 0; zrl < 3; zrl++)
    if(zlr * zrl < 2) { // pi[2] may only be neighbor with pi[0]
        for(int zll = 0; zll < 3; zll++)
        for(int zrr = 0; zrr < 3; zrr++) {
            res[zll][zrr] = max(res[zll][zrr], a[zll][zlr] + b[zrl][zrr]);
        }
    }
    return res;
}

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        for(int z = 0; z < 3; z++) {
            mx[v][z][z] = pi[z] * c;
        }
    } else {
        int m = (l + r) / 2;
        if(p < m) {
            upd(p, c, 2 * v, l, m);
        } else {
            upd(p, c, 2 * v + 1, m, r);
        }
        mx[v] = concat(mx[2 * v], mx[2 * v + 1]);
    }
}

tab get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return mx[v];
    } else if(r <= a || b <= l) {
        return tab();
    } else {
        int m = (l + r) / 2;
        return concat(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
    }
}

void solve() {
    int n, q, x, y, b;
    cin >> n >> q >> x >> y;
    pi = {0, max(x, y), x + y};
    for(int i = 0; i < n; i++) {
        cin >> b;
        upd(i, b);
    }
    double den = 1. / max(x, y) / (x + y);
    cout << fixed << setprecision(12);
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            upd(a - 1, b);
        } else {
            auto res = get(a - 1, b);
            int ans = 0;
            for(int l = 0; l < 3; l++) {
                for(int r = 0; r < 3; r++) {
                    ans = max(ans, res[l][r]);
                }
            }
            cout << ans * den << "\n";
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;// cin >> t;
    while(t--) {
        solve();
    }
}