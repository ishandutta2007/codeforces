#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

bool ok(const string& s, const string& t) {
  if (s.size() % t.size()) return false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != t[i % t.size()]) return false;
  }
  return true;
}

void solve() {
  string s, t;
  cin >> s >> t;
  string ss = s;
  for (int it = 0; it <= t.size(); ++it) {
    if (ok(ss, t)) {
      cout << ss << "\n";
      return;
    }
    ss += s; 
  }
  cout << "-1\n";
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