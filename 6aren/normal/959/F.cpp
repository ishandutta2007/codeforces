#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;
const int MOD = 1000000007;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

// int inv(int x) {
//     return power(x, MOD - 2);
// }

// int fac[N], ifac[N];

// void init_combi() {
//     fac[0] = 1;
//     ifac[0] = 1;
//     for (int i = 1; i < N; i++) {
//         fac[i] = 1LL * fac[i - 1] * i % MOD;
//         ifac[i] = inv(fac[i]); 
//     }
// }

// int C(int n, int k) {
//     return 1LL * ifac[k] * ifac[n - k] % MOD * fac[n] % MOD;
// }

vector<ii> que[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int l, x;
        cin >> l >> x;
        que[l].pb({x, i});
    }
    vector<int> basis;
    for (int i = 1; i <= n; i++) {
        for (int b : basis) {
            if ((a[i] ^ b) < a[i]) a[i] ^= b;
        }
        if (a[i] > 0) {
            for (int &b : basis) {
                if ((b ^ a[i]) < b) b ^= a[i];
            }
            basis.pb(a[i]);
        }
        for (auto e : que[i]) {
            int x = e.x;
            int id = e.y;
            for (int b : basis) {
                if ((x ^ b) < x) x ^= b; 
            }
            if (x == 0) ans[id] = power(2, i - basis.size());
            else ans[id] = 0;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}