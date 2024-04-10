#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

int a[N];

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    //a[i] = (x - a[i] + 1) / a[i];
  }
  sort(a, a + n, greater<int>());

  int ans = 0;
  int i = 0;

  ll sum = 0, cnt = 0; 

  while (i < n) {
    if (a[i] * (cnt + 1) >= x) {
      ans++;
      sum = cnt = 0;
    } else {
      cnt++;
    }
    i++;
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