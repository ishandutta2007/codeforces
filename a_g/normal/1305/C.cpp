#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]%m]++;
  }
  for (int x: b) {
    if (x > 1) {
      cout << "0\n";
      return 0;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      ans = 1LL * ans * abs(a[i]-a[j]) % m;
    }
  }
  cout << ans << '\n';
}