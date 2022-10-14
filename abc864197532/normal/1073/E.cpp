#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 300087, K = 111;

lli solve(lli bound, int k) {
    string t = to_string(bound);
    int n = t.length();
    lli dp[n + 1][1 << 10][2][2], cnt[n + 1][1 << 10][2][2];
    for (int i = 0; i <= n; ++i) for (int s = 0; s < 1 << 10; ++s) {
        for (int f : {0, 1}) for (int z : {0, 1}) {
            dp[i][s][f][z] = cnt[i][s][f][z] = 0;
        }
    }
    cnt[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i) for (int s = 0; s < 1 << 10; ++s) {
        // (0, 0)
        for (int d = 0; d <= t[i] - '0'; ++d) {
            (dp[i + 1][d ? 1 << d : 0][d < t[i] - '0'][d ? 1 : 0] += dp[i][s][0][0] * 10 + cnt[i][s][0][0] * d) %= mod;
            (cnt[i + 1][d ? 1 << d : 0][d < t[i] - '0'][d ? 1 : 0] += cnt[i][s][0][0]) %= mod;
        }
        // (0, 1)
        for (int d = 0; d <= t[i] - '0'; ++d) {
            (dp[i + 1][s | 1 << d][d < t[i] - '0'][1] += dp[i][s][0][1] * 10 + cnt[i][s][0][1] * d) %= mod;
            (cnt[i + 1][s | 1 << d][d < t[i] - '0'][1] += cnt[i][s][0][1]) %= mod;
        }
        // (1, 0)
        for (int d = 0; d < 10; ++d) {
            (dp[i + 1][d ? 1 << d : 0][1][d ? 1 : 0] += dp[i][s][1][0] * 10 + cnt[i][s][1][0] * d) %= mod;
            (cnt[i + 1][d ? 1 << d : 0][1][d ? 1 : 0] += cnt[i][s][1][0]) %= mod;
        }
        // (1, 1)
        for (int d = 0; d < 10; ++d) {
            (dp[i + 1][s | 1 << d][1][1] += dp[i][s][1][1] * 10 + cnt[i][s][1][1] * d) %= mod;
            (cnt[i + 1][s | 1 << d][1][1] += cnt[i][s][1][1]) %= mod;
        }
    }
    lli ans = 0;
    for (int s = 0; s < 1 << 10; ++s) if (__builtin_popcount(s) <= k) (ans += dp[n][s][1][1]) %= mod;
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli l, r;
    int k;
    cin >> l >> r >> k, r++;
    cout << (solve(r, k) + mod - solve(l, k)) % mod << endl;
}