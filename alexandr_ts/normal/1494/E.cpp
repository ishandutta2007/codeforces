#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 510;

void solve() {
  int n, m;
  cin >> n >> m;

  int cnt_same = 0;
  int cnt_dif = 0;

  map<pair<int, int>, char> labels;

  for (int iq = 0; iq < m; ++iq) {
    char typ;
    cin >> typ;
    if (typ == '+') {
      int u, v;
      char c;
      cin >> u >> v >> c;
      labels[{u, v}] = c;
      auto it = labels.find({v, u});
      if (it != labels.end()) {
        if (it->second == c) {
          cnt_same++;
        } else {
          cnt_dif++;
        }
      }
    } else if (typ == '-') {
      int u, v;
      cin >> u >> v;
      auto it = labels.find({v, u});
      char c = labels[{u, v}];
      if (it != labels.end()) {
        if (it->second == c) {
          cnt_same--;
        } else {
          cnt_dif--;
        }
      }
      labels.erase({u, v});
    } else {
      assert(typ == '?');
      int k;
      cin >> k;
      if (cnt_same > 0 || (cnt_dif > 0 && k % 2)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}