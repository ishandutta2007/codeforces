#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll a[N], c[N];

void solve() {
  for (int i = 0; i < 3; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < 3; ++i) {
    c[i] -= a[i];
    if (c[i] < 0) {
      cout << "NO\n";
      return;
    }
  }

  int b1 = min(a[3], c[0]);
  a[3] -= b1, c[0] -= b1;

  c[2] -= a[3];

  int b2 = min(a[4], c[1]);
  a[4] -= b2, c[1] -= b2;

  c[2] -= a[4];

  if (c[2] >= 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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