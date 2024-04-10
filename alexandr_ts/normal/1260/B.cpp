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
  ll a, b;
  cin >> a >> b;
  if ((a + b) % 3) {
    cout << "NO\n";
    return;
  }

  if (a > b) swap(a, b);
  if (a * 2 < b) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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