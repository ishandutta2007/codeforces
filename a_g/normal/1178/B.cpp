#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a(n);
  for (int i = 1; i < n; i++) {
    a[i] = a[i-1] + (s[i] == 'v' && s[i-1] == 'v');
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      ans += 1LL * a[i] * (a[n-1]-a[i]);
    }
  }
  cout << ans << '\n';
}