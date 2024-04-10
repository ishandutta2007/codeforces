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

  int n, m;

  cin >> n >> m;
  vector<int> a(n), b(m);

  for (int _ = 0; _ < 2; ++_) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        a[i] ^= x;
        b[j] ^= x;
      }
  }

  bool ok = true;
  for (int i = 0; i < n; ++i)
    ok &= a[i] == 0;
  for (int j = 0; j < m; ++j)
    ok &= b[j] == 0;

  cout << (ok ? "Yes" : "No") << "\n";
}