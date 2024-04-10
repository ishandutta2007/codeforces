#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

lli fac[N], facp[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

void build() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
    for (int i = 0; i < N; ++i) facp[i] = modpow(fac[i], mod - 2);
}

lli C(int n, int m) {
    if (n < m) return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (m == 1) {
        cout << n << endl;
        return;
    }
    sort(all(a));
    lli ans = 0, now = 0;
    for (int i = 0, j = 1; i < n; ++i) {
        while (j < n && a[j] - a[i] <= k) {
            j++;
            now = (now + C(j - i - 2, m - 2)) % mod;
        }
        ans = (ans + now) % mod;
        now = (now + mod - C(j - i - 2, m - 2)) % mod;
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}