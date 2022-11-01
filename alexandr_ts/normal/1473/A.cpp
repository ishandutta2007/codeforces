#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int a[N];

void solve() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] > d && a[0] + a[1] > d) ok = false;
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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