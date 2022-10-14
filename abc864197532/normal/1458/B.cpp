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

int dp[101][10001];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int j = 0; j <= 100; ++j) for (int i = 0; i <= 10000; ++i) dp[j][i] = -1 << 30;
  dp[0][0] = 0;
  int n, w = 0;
  cin >> n;
  for (int t = 0, a, b; t < n; ++t) {
    cin >> a >> b;
    w += b;
    for (int j = 100; j > 0; --j) {
      for (int i = 10000; i >= a; --i) {
        dp[j][i] = max(dp[j][i], dp[j - 1][i - a] + b);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 0; j <= 10000; ++j) {
      ans = max(ans, min(w + dp[i][j], 2 * j));
    }
    cout << double(ans) / 2 << ' ';
  }
}