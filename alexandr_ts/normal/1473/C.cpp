#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

void solve() {
  int n, k;
  cin >> n >> k;
  int f = 2 * k - 1 - n;
  for (int i = 1; i <= f; ++i) {
    cout << i << " ";
  }
  for (int i = k; i >= f + 1; --i) {
    cout << i << " ";
  }
  cout << "\n";
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