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
  string s;
  cin >> s;
  bool has0 = false, has1 = false;
  for (int i = 0; i + 1 < (int)s.size(); ++i) {
    if (s[i] == '1' && s[i + 1] == '1') {
      has1 = true;
    }
    if (s[i] == '0' && s[i + 1] == '0' && has1) {
      has0 = true;
    }
  }
  if (has0 && has1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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