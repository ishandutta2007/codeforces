#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll s[N];

void solve() {
  int n, m, a1, b1;
  cin >> n >> m >> a1 >> b1;

  if (a1 > b1) {
    a1 = n + 1 - a1;
    b1 = n + 1 - b1;
  }

  int a = a1 - 1;
  int b = b1 - a1;

  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }
  sort(s, s + m);

  int tl = -1, tr = m;
  while (tr - tl > 1) {
    int tm = (tl + tr) / 2;
    bool ok = true; 
    if (tm + 1 > b - 1) {
      ok = false;
    } else {
      for (int i = tm; i >= 0; --i) {
        if (s[i] > a + b - 1 - (tm - i)) {
          ok = false;
        }     
      }
    }
    if (ok) {
      tl = tm;
    } else {
      tr = tm;
    }
  }
  cout << tl + 1 << "\n";

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