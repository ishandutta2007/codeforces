#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 1e9 + 7;

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

const int maxn = 3e6 + 42;
int F[maxn], RF[maxn];

int fact(int n) {
    return F[n];
}

int rfact(int n) {
    return RF[n];
}

int nCr(int n, int r) {
    return mul(fact(n), mul(rfact(r), rfact(n - r)));
}

void solve() {
    F[0] = 1;
    for(int i = 1; i < maxn; i++) {
        F[i] = mul(F[i - 1], i);
    }
    RF[maxn - 1] = inv(F[maxn - 1]);
    for(int i = 1; i < maxn; i++) {
        RF[maxn - i - 1] = mul(RF[maxn - i], maxn - i);
    }
    int n, q;
    cin >> n >> q;
    const int sz = 3 * (n + 1);
    int num[sz + 1], ans[3 * n + 1];
    fill(ans, ans + sz + 1, 0);
    num[0] = 0;
    for(int i = 1; i <= sz; i++) {
        num[i] = nCr(sz, i);
    }
    // f[n-3] + 3*f[n-2] + 3*f[n-1] = g[n]
    int d = inv(3);
    for(int i = 0; i <= 3 * n; i++) {
        ans[i] = num[i + 1];
        if(i >= 1) {
            ans[i] = sub(ans[i], mul(3, ans[i - 1]));
        }
        if(i >= 2) {
            ans[i] = sub(ans[i], ans[i - 2]);
        }
        ans[i] = mul(ans[i], d);
    }
    while(q--) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
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