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
  vector<int> a, b;
  int ans = 0;
  for (auto c: s) {
    if (c == '(') {
      a.push_back(1);
    } else if (c == ')') {
      if (!a.empty()) {
        ans++;
        a.pop_back();
      }
    } else if (c == '[') {
      b.push_back(1);
    } else {
      if (!b.empty()) {
        ans++;
        b.pop_back();
      }
    }
  }
  cout << ans << "\n";
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