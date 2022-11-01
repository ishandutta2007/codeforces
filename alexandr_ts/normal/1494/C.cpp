#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int calc(vector<int> a, vector<int> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int n = a.size();

  set<int> b_set = {b.begin(), b.end()};

  vector<int> is_in_good(n, 0);
  for (int i = 0; i < n; ++i) {
    if (b_set.count(a[i])) {
      is_in_good[i] = 1;
    }
  }

  int under = accumulate(is_in_good.begin(), is_in_good.end(), 0);

  int ptr = 0;
  int ans = under;
  for (auto pos: b) {
    int me = pos - 1; 
    while (ptr < n && a[ptr] - ptr <= me) {
      if (is_in_good[ptr]) {
        under--;
      }
      ptr++;
    }
    int pref = 0;
    if (ptr > 0) {
      int l = pos;
      int r = pos + ptr - 1;
      auto itr = upper_bound(b.begin(), b.end(), r);
      auto itl = lower_bound(b.begin(), b.end(), l);
      pref = itr - itl;
    }
    ans = max(ans, under + pref);
  }
  return ans;
}

int solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a1, a2;
  vector<int> b1, b2;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > 0) {
      a1.push_back(x);
    } else {
      a2.push_back(-x);
    }
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    if (x > 0) {
      b1.push_back(x);
    } else {
      b2.push_back(-x);
    }
  }

  return calc(a1, b1) + calc(a2, b2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		auto rez = solve();
    cout << rez << "\n";
	}
}