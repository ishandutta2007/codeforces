#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}
int sub(int a, int b) {
    return (a + mod - b) % mod;
}
int mul(int a, int b) {
    return a * b % mod;
}
int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
    return bpow(x, mod - 2);
}

const int maxn = 1e5 + 42;
const int maxs = 4 * maxn;

int c[maxn];
int sm[maxs], mnp[maxs], mxp[maxs];

void build(int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        sm[v] = mnp[v] = mxp[v] = c[l];
    } else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m, r);
        sm[v] = sm[2 * v] + sm[2 * v + 1];
        mnp[v] = min(mnp[2 * v], sm[2 * v] + mnp[2 * v + 1]);
        mxp[v] = max(mxp[2 * v], sm[2 * v] + mxp[2 * v + 1]);
    }
}

tuple<int, int, int> get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return {sm[v], mnp[v], mxp[v]};
    } else if(r <= a || b <= l) {
        return {0, 0, 0};
    } else {
        int m = (l + r) / 2;
        auto [s1, mn1, mx1] = get(a, b, 2 * v, l, m);
        auto [s2, mn2, mx2] = get(a, b, 2 * v + 1, m, r);
        return make_tuple(s1 + s2,
            min(mn1, s1 + mn2),
            max(mx1, s1 + mx2)
        );
    }
}


void solve() {
    int n, q;
    cin >> n >> q;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = b[i] - a[i];
    }
    build();
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        auto [s, mn, mx] = get(l - 1, r);
        if(s != 0 || mn < 0) {
            cout << -1 << "\n";
        } else {
            cout << mx << "\n";
        }
    }
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}