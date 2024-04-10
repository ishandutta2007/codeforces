#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n, m, k;

  cin >> n >> m >> k;

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    b[i] -= i;
  }

  vector<int> a;
  for (int i = 0; i + 1 < n; ++i)
    a.push_back(b[i + 1] - b[i]);

  sort(all(a));

  int use = max(0, (n - k));

  int ans = n;
  for (int i = 0; i < use; ++i)
    ans += a[i];

  cout << ans << "\n";
}