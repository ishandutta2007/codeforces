#include <bits/stdc++.h>

using namespace std;

int n, a[69];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = a[3];
  sort(a + 1, a + n + 1);
  ans ^= a[1]; ans += 2;
  cout << ans << endl;
  return 0;
}