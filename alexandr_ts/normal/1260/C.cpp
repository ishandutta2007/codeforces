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
  ll r, b, k;
  cin >> r >> b >> k;
  ll g = __gcd(r, b);
  r /= g, b /= g;
  if (r > b) swap(r, b);
  ll mx = (b - 2) / r + 1;
  if (r == b) mx = 1;
  if (mx < k) {
    cout << "OBEY\n";
  } else {
    cout << "REBEL\n";
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin>> t;
	while (t--) {
		solve();
	}
}