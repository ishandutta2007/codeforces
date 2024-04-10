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
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 3e6;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <pii> a(n);
    lli ans = 0;
    for (int i = 0; i < n; ++i) cin >> a[i].X, a[i].Y = 1, ans += a[i].X;
    deque <pii> dq(all(a));
    while (!dq.empty() && dq.front().X % x == 0) {
      int v, t;
      tie(v, t) = dq.front(); dq.pop_front();
      ans += v * t;
      dq.push_back({v / x, t * x});
    }
    cout << ans << endl;
  }
}