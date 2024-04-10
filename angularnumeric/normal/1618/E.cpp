#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, i, j;
  cin >> n;
  vector<long long int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  long long int sum = 0;
  for (i = 0; i < n; i++) sum += a[i];
  if (sum % (n * (n + 1) / 2) != 0) {
    cout << "NO" << '\n';
    return;
  }
  long long int k = sum / (n * (n + 1) / 2);
  vector<long long int> ans(n);
  for (i = 0; i < n; i++) {
    long long int t = 0;
    if (i == 0)
      t = a[n - 1];
    else
      t = a[i - 1];
    long long int p = k - (a[i] - t);
    if (p % n != 0) {
      cout << "NO" << '\n';
      return;
    }
    ans[i] = p / n;
    if (ans[i] <= 0) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  for (i = 0; i < n; i++) cout << ans[i] << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}