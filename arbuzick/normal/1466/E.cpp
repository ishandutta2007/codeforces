#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINES
const int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    vector<int> cnt(62);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (x[i]&(1LL << j))
                cnt[j]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < 62; ++j) {
            if (x[i]&(1LL << j)) {
                s1 = s1+(1LL << j)%mod*cnt[j];
                s1 %= mod;
            }
        }
        for (int j = 0; j < 62; ++j) {
            if (x[i]&(1LL << j)) {
                s2 = s2+(1LL << j)%mod*n;
                s2 %= mod;
            } else {
                s2 = s2+(1LL << j)%mod*cnt[j];
                s2 %= mod;
            }
        }
        ans = ans+s1*s2%mod;
        ans %= mod;
    }
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}