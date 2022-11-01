#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

ll a[N];

void solve() {
  int n;
  cin >> n;
  ll fr = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == -1) {
      fr = i; 
    }
  }
 
  ll ans = 0;
  multiset<ll> vals;
  for (int i = n; i >= 1; --i) {
    if (i != fr) {
      vals.insert(a[i]);
    } else {
      break;
    }
    if (!(i & (i - 1))) {
      ans += *vals.begin();
      vals.erase(vals.begin());
    }
  } 
  cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}