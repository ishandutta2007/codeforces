#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n, a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    int current_layer = 1, ptr = 2, ans = 0;
    while (ptr <= n) {
      ++ans;
      // cerr << current_layer << " " << ptr << '\n';
      int next_layer = 0;
      while (ptr <= n and current_layer--) {
        ++next_layer;
        while (ptr + 1 <= n and a[ptr + 1] > a[ptr]) ++ptr, ++next_layer;
        ++ptr;
      }
      current_layer = next_layer;
    }
    cout << ans << '\n';
  }
  return 0;
}