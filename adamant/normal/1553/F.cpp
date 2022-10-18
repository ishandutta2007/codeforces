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

const int maxn = 3e5 + 42;
int total = 0, sum = 0;
int S[maxn], C[maxn], TS[maxn], TC[maxn];
const size_t magic = 450;

void recalc(int *L, int *R) {
    memset(TS, 0, sizeof TS);
    memset(TC, 0, sizeof TC);
    for(auto it = L; it != R; it++) {
        total += 1;
        sum += *it;
        TC[*it]++;
        for(int i = *it; i < maxn; i += *it) {
            TS[i] += *it;
        }
    }
    for(int i = 0; i < maxn; i++) {
        if(i > 0) {
            TS[i] += TS[i - 1];
            TC[i] += TC[i - 1];
        }
        S[i] += TS[i];
        C[i] += TC[i];
    }
}

int arem(int a) { // sum a % a[i]
    return a * total - S[a];
}

int rema(int a) { // sum a[i] % a
    int res = sum;
    for(int ai = 0; ai < maxn; ai += a) {
        res -= ai * (C[min(ai + a - 1, maxn - 1)] - C[ai ? ai - 1 : 0]);
    }
    return res;
}

void solve() {
    size_t n;
    cin >> n;
    int a[n];
    int ans[n];
    fill(ans, ans + n, 0);
    for(size_t i = 0; i < n; i += magic) {
        for(size_t j = 0; j < min(n - i, magic); j++) {
            cin >> a[i + j];
            for(size_t k = 0; k < j; k++) {
                ans[i + j] += a[i + k] % a[i + j] + a[i + j] % a[i + k];
            }
            ans[i + j] += rema(a[i + j]) + arem(a[i + j]);
        }
        recalc(a + i, a + min(n, i + magic));
    }
    partial_sum(ans, ans + n, ans);
    for(size_t i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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