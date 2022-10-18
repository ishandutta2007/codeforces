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

const int maxn = 6001;
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

bitset<maxn> d[maxn];

void solve() {
    int n;
    cin >> n;
    int x[n], y[n];
    int cnt[4];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        x[i] = 2 * (rand() % 40);
        y[i] = 2 * (rand() % 40);
        cin >> x[i] >> y[i];
        x[i] /= 2;
        y[i] /= 2;
        int xx = x[i] & 1;
        int yy = y[i] & 1;
        cnt[2 * xx + yy]++;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            d[i][j] = d[j][i] = (((x[i] - x[j]) & 1) != 0) || (((y[i] - y[j]) & 1) != 0);
        }
    }
    // #(i, j, k) : (d[i][j] ^ d[j][k] ^ d[k][i]) = 0 (mod 2)
    int ans = 0;
    for(int x0 = 0; x0 <= 1; x0++)
    for(int y0 = 0; y0 <= 1; y0++)
    for(int x1 = 0; x1 <= 1; x1++)
    for(int y1 = 0; y1 <= 1; y1++)
    for(int x2 = 0; x2 <= 1; x2++)
    for(int y2 = 0; y2 <= 1; y2++) {
        int d01 = (x0 ^ x1) | (y0 ^ y1);
        int d02 = (x0 ^ x2) | (y0 ^ y2);
        int d12 = (x1 ^ x2) | (y1 ^ y2);
        int t0 = 2 * x0 + y0;
        int t1 = 2 * x1 + y1;
        int t2 = 2 * x2 + y2;
        if((d01 ^ d12 ^ d02) == 0) {
            if(t0 == t1 && t1 == t2) {
                ans += cnt[t0] * (cnt[t0] - 1) * (cnt[t0] - 2);
            } else if(t0 == t1) {
                ans += cnt[t0] * (cnt[t0] - 1) * cnt[t2];
            } else if(t0 == t2) {
                ans += cnt[t0] * (cnt[t0] - 1) * cnt[t1];
            } else if(t1 == t2) {
                ans += cnt[t1] * (cnt[t1] - 1) * cnt[t0];
            } else {
                ans += cnt[t0] * cnt[t1] * cnt[t2];
            }
        }
    }
    cout << ans / 6 << "\n";
    //cout << clock() / double(CLOCKS_PER_SEC) << endl;
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