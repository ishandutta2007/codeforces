#include <bits/stdc++.h>

using namespace std;

int b, g, n, ans;

int main() {
  cin >> b >> g >> n;
  for (int i = 0; i <= min(n, b); ++i) {
    int j = n - i;
    if (i <= b and j <= g) ++ans;
  }
  cout << ans << '\n';
  return 0;
}