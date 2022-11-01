#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e5 + 10;

void solve() {
  int x;
  cin >> x;
  int val = 0;
  int cur = 1;
  int ans = 0;
  while (val < x) {
    val += cur;
    cur++;
    ans++;
  }

  if (x + 1 == val) {
    ans++; 
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