#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

struct Pt {
  int x, y;
};

void solve() {
  int n;
  cin >> n;

  map<pair<int, int>, ll> cnt;

  for (int i = 0; i < n; ++i) {
    Pt p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Pt p = {p2.x - p1.x, p2.y - p1.y};
    int g = __gcd(abs(p.x), abs(p.y));
    p.x /= g;
    p.y /= g;
    cnt[{p.x, p.y}]++;
  }

  ll ans = 0;
  for (auto [v, c]: cnt) {
    ans += c * cnt[{-v.first, -v.second}];
  }

  cout << ans / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}