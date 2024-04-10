#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      int x; scanf("%d", &x); x = abs(x);
      if (i & 1) printf("%d ", x); else printf("%d ", -x);
    }
    cout << '\n';
  }
  return 0;
}