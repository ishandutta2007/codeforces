#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, a, m;
  cin >> n >> k >> a >> m;
  ++a;
  set<int> s = {0, n+1};
  for (int i = 1, c = (n+1) / a, x; i <= m; ++i) {
    cin >> x;
    auto it = s.lower_bound(x);
    int r = *it, l = *--it;
    c += (r - x) / a + (x - l) / a - (r - l) / a;
    if (c < k) {
      cout << i;
      return 0;
    }
    s.insert(x);
  }
  cout << -1;
  return 0;
}