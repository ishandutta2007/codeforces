#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  vector<int> s(n+1);
  for (int i = 0; i < n; i++) {
    s[i+1] = s[i]^a[i];
  }
  for (int i = 0; i+2 < n; i++) {
    if (__lg(a[i]) == __lg(a[i+2])) {
      cout << "1\n";
      return 0;
    }
  }
  assert(n < 100);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k <= n; k++) {
        if ((s[i]^s[j]) > (s[j]^s[k])) {
          ans = min(ans, k-i-2);
        }
      }
    }
  }
  if (ans == 1e9) ans = -1;
  cout << ans << '\n';
}