#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (int& x : a) { cin >> x; --x; }
  sort(all(a));

  auto between = [&](int x0, int x1) {
    if (x1 > x0) {
      return x1 - x0 - 1;
    } else {
      return x1 + (n - x0) - 1;
    }
  };

  vector<int> gaps;
  for (int i = 0; i < m; ++i) {
    int x0 = a[i];
    int x1 = a[(i + 1) % m];
    int g = between(x0, x1);
    gaps.push_back(g);
  }
  sort(all(gaps));
  reverse(all(gaps));

  int t = 0;
  li ans = 0;
  for (int g : gaps) {
    int l = g - 2 * t;
    if (l <= 0) continue;
    ans += max(l - 1, 1);
    t += 2;
  }

  ans = n - ans;
  assert(ans >= 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}