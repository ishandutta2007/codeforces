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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (m == 1 || n == 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << 'X';
      }
      cout << "\n";
    }
    return;
  }

  for (int j = 0; j + 1 < m; j += 3) {
    for (int i = 0; i < n; ++i) {
      a[i][j + 1] = 'X';
    } 
  }

  int blocks = (m + 1) / 3;
  for (int b = 1; b < blocks; ++b) {
    int j = 3 * b - 1;
    bool fnd = false;
    for (int i = 0; !fnd && i < n; ++i) {
      if (a[i][j] == 'X') {
        a[i][j + 1] = 'X';
        fnd = true;
      } else if (a[i][j + 1] == 'X') {
        a[i][j] = 'X';
        fnd = true;
      }
    }
    if (!fnd) {
      a[0][j] = a[0][j + 1] = 'X';
    }
  }

  if (m % 3 == 1) {
    for (int i = 0; i < n; ++i) {
      if (a[i][m - 1] == 'X') {
        a[i][m - 2] = 'X';
      }
    }
  }
  for (auto s: a) {
    cout << s << "\n";
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