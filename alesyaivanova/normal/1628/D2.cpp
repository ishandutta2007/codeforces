#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e6 + 9;
int f[maxn];
int rf[maxn];

int mod = 1e9 + 7;

int add(int x, int y) {
    return (x + y) % mod;
}

int mul(int x, int y) {
    return (x * 1ll * y) % mod;
}

int binpow(int a, int p) {
    int ans = 1;
    while (p) {
        if (p % 2 == 1) {
            ans = mul(ans, a);
        }
        p /= 2;
        a = mul(a, a);
    }
    return ans;
}

int divv(int x, int y) {
    return mul(x, binpow(y, mod - 2));
}

void prec() {
    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = mul(f[i - 1], i);
    }
    rf[maxn - 1] = divv(1, f[maxn - 1]);
    for (int i = maxn - 2; i >= 0; i--) {
        rf[i] = mul(rf[i + 1], i + 1);
    }
}

int C(int N, int K) {
    return mul(f[N], mul(rf[K], rf[N - K]));
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n == m) {
        cout << mul(n, k) << "\n";
        return;
    }
    int d = 1;
    int t = 0;
    while (m != n - 1) {
        d = mul(d, 2);
        n--;
        t++;
    }
    int e = 0;
    int ans = 0;
    while (n != 1) {
        int cur = divv(C(t, e), mul(d, 2));
        cur = mul(cur, n - 1);
        ans = add(ans, cur);
        d = mul(d, 2);
        t++;
        e++;
        n--;
        m--;
    }
    cout << mul(ans, k) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prec();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}