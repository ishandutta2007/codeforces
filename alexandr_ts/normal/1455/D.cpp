#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e5 + 10;

int a[N];

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (is_sorted(a, a + n)) {
      cout << ans << "\n";
      return;
    }
    int pos = 0;
    for (; pos < n; ++pos) {
      if (a[pos] > x) {
        break;
      }
    }
    if (pos == n) break;
    swap(a[pos], x);
    ans++;
  }

  if (is_sorted(a, a + n)) {
    cout << ans << "\n";
  } else {
    cout << "-1\n";
  }
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