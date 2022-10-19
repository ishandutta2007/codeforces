#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

int n, m;
int a[M];
int b[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  a[n++] = 1e9;

  for (int i = 0; i < m; ++i) {
    int l, r, y;
    cin >> l >> r >> y;
    if (l == 1) {
      int at = upper_bound(a, a + n, r) - a - 1;
      if (at >= 0)
        b[at]++;
    }
  }

  for (int i = n - 1; i > 0; --i)
    b[i - 1] += b[i];

  int ans = n + m;
  for (int i = 0; i < n; ++i)
    ans = min(ans, i + b[i]);

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
}