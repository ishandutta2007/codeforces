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
  string t;
  cin >> t;
  int r = 0, p = 0, s = 0;
  r = count(t.begin(), t.end(), 'R');
  p = count(t.begin(), t.end(), 'P');
  s = count(t.begin(), t.end(), 'S');

  char ch = 'R';
  int mx = max(max(r, p), s);
  if (r == mx) {
    ch = 'P';
  } else if (p == mx) {
    ch = 'S';
  } else {
    ch = 'R';
  }
  for (int i = 0; i < t.size(); ++i) {
    cout << ch;
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