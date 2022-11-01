#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

bool ok(int n, int u, int r, int d, int l) {
  if (u < 0 || u > n - 2) return false;
  if (l < 0 || l > n - 2) return false;
  if (d < 0 || d > n - 2) return false;
  if (r < 0 || r > n - 2) return false;
  return true;
}

bool solve() {
  int n, u, r, d, l;
  cin >> n >> u >> r >> d >> l;

  for (int ur = 0; ur <= 1; ++ur) {
    for (int rd = 0; rd <= 1; ++rd) {
      for (int dl = 0; dl <= 1; ++dl) {
        for (int lu = 0; lu <= 1; ++lu) {
          if (ok(n, u - ur - lu, r - ur - rd, d - rd - dl, l - dl - lu)) return true;
        }
      }
    }
  }

  return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		auto rez = solve();
    if (rez) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
	}
}