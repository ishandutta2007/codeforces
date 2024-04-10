#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = n + 1;
  int best = 1;

  for (int i = 1; i <= n; ++i)
    if (ans > (i + (n + i - 1) / i)) {
      best = i;
      ans = i + (n + i - 1) / i;
    }
  
  int a = best;
  int b = (n + a - 1) / a;
  assert(1ll * a * b >= n);

  vector<int> t;
  for (int i = 0; i < n; i += a) {
    for (int j = min(i + a - 1, n - 1); j >= i; --j)
      t.push_back(j);
  }

  for (int x : t)
    cout << x + 1 << " ";
  cout << "\n";
}