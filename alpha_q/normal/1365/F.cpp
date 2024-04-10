#include <bits/stdc++.h>

using namespace std;

int t, n, a[569], b[569];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) scanf("%d", b + i);
    if ((n & 1) and a[1 + n >> 1] ^ b[1 + n >> 1]) {
      cout << "No\n";
      continue;
    }
    vector <pair <int, int>> x, y;
    for (int i = 1, j = n; i < j; ++i, --j) {
      x.emplace_back(min(a[i], a[j]), max(a[i], a[j]));
      y.emplace_back(min(b[i], b[j]), max(b[i], b[j]));
    }
    sort(x.begin(), x.end()), sort(y.begin(), y.end());
    puts(x == y ? "Yes" : "No");
  }
  return 0;
}