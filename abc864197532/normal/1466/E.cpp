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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17, K = 3e6;

void solve() {
    int n;
    cin >> n;
    vector <lli> cnt(60, 0);
    vector <lli> a(n);
    lli al = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        (al += a[i]) %= mod;
        for (int j = 0; j < 60; ++j) {
            if (a[i] & (1ll << j)) cnt[j]++;
        }
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        lli andsum = 0;
        for (int j = 0; j < 60; ++j) {
            if (a[i] & (1ll << j)) {
                (andsum += (1ll << j) % mod * cnt[j] % mod) %= mod;
            }
        }
        lli plussum = (al + a[i] % mod * n) % mod;
        ans = (ans + plussum * andsum - andsum * andsum) % mod;
    }
    if (ans < 0) ans += mod;
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}