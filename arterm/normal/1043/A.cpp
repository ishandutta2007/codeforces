#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  ll n, sum = 0;
  ll mx = 0;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    sum += x;
    mx = max(mx, x);
  }
  // k * n - sum > sum
  
  ll k = (2 * sum) / n + 1;
  k = max(k, mx);
  cout << k << "\n";
}