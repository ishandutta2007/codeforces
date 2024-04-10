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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

int dp[76][1 << 20];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) dp[i][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int s = 0; s < 1 << 20; ++s) if (dp[i][s]) {
            int now = 0;
            for (int j = i; j < n; ++j) {
                now = now << 1 | (t[j] - '0');
                if (now >= 21) break;
                if (now) dp[j + 1][s | (1 << now - 1)] = (dp[j + 1][s | (1 << now - 1)] + dp[i][s]) % mod;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= 20; ++i) {
            ans = (ans + dp[j][(1 << i) - 1]) % mod;
        }
    }
    cout << ans << endl;
}