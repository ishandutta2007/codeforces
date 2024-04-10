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
const int mod = 1e9 + 7, abc = 864197532, N = 402, logN = 17, K = 333, INF = 5e8;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <vector <lli>> dp(n + 1, vector <lli> (n + 1, 1));
  for (int d = 2; d <= n; ++d) for (int i = 0; i + d <= n; ++i) {
    int j = i + d;
    dp[i][j] = dp[i + 1][j];
    for (int k = i + 2; k < j; ++k) {
      if (a[i + 1] < a[k]) {
        (dp[i][j] += 1ll * dp[i + 1][k] * dp[k - 1][j]) %= mod;
      }
    }
  }
  cout << dp[0][n] << endl;
}