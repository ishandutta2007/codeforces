#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

bool valid(string s) {
  int bal = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == ')') {
      if (bal == 0) return false;
      bal--;
    } else {
      bal++;
    }
  }
  return bal == 0;
}

void solve() {
  string s;
  cin >> s;
  for (int a = 0; a <= 1; ++a) {
    for (int b = 0; b <=1; ++b) {
      for (int c = 0; c <=1; ++c) {
        string t;
        for (auto ch: s) {
          if (ch == 'A') {
            t += (char)('(' + a);
          } else if (ch == 'B') {
            t += (char)('(' + b);
          } else {
            t += (char)('(' + c);
          }
        }
        if (valid(t)) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
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