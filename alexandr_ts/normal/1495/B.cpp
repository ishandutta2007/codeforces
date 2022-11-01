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
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto& x: p) cin >> x;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    l[i] = 1;
    if (i && p[i] > p[i - 1]) l[i] = l[i - 1] + 1;
  }

  for (int i = n - 1; i >= 0; --i) {
    r[i] = 1;
    if (i + 1 < n && p[i] > p[i + 1]) r[i] = r[i + 1] + 1;
  }

  int mx = max(*max_element(l.begin(), l.end()), *max_element(r.begin(), r.end()));
  int cnt = count(l.begin(), l.end(), mx) +  count(r.begin(), r.end(), mx);
  if (cnt != 2) {
    cout << 0 << endl;
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (l[i] == r[i] && l[i] == mx && l[i] % 2) {
      cout << 1 << endl;
      return;
    } 
  }  
  cout << 0 << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}