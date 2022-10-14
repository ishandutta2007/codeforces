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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17;

double dp[1 << 18][18];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    double p[n][n];
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> p[i][j];
    dp[1][0] = 1;
    for (int s = 0; s < 1 << n; s++) if (__builtin_popcount(s) > 1) {
        for (int i = 0; i < n; ++i) if (s & (1 << i)) {
            for (int j = 0; j < n; ++j) if (s & (1 << j) && i ^ j) {
                dp[s][i] = max(dp[s][i], dp[s ^ (1 << j)][i] * p[i][j] + dp[s ^ (1 << i)][j] * p[j][i]);
            }
        }
    }
    cout << fixed << setprecision(10) << *max_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n) << endl;
}