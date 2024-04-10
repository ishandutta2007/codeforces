#include <bits/stdc++.h>

using namespace std;

int n;
long long a[569];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, a[i]);
    for (int j = i + 1; j < n; ++j) {
      ans = max(ans, a[i] | a[j]);
      for (int k = j + 1; k < n; ++k) {
        ans = max(ans, a[i] | a[j] | a[k]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}