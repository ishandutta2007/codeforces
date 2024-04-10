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

const int maxn = 5e5 + 9;
const int lg = 61;
int cnt[lg];
int x[maxn];
int n;
int mod = 1e9 + 7;

void solve() {
    for (int e = 0; e < lg; e++)
        cnt[e] = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        for (int e = 0; e < lg; e++) {
            if (x[i] & (1ll << e))
                cnt[e]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int kek1 = 0, kek2 = 0;
        for (int e = 0; e < lg; e++) {
            int u = (1ll << e);
            u %= mod;
            if (x[i] & (1ll << e)) {
                kek1 = (kek1 + cnt[e] * u) % mod;
                kek2 = (kek2 + n * u) % mod;
            } else {
                kek2 = (kek2 + cnt[e] * u) % mod;
            }
        }
        ans = (ans + kek1 * kek2) % mod;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}