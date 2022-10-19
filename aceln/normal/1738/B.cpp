#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> pre(n + 1), a(n + 1);
    for (int i = n - k + 1; i <= n; i++)
      cin >> pre[i];

    if (k == 1) {
      cout << "YES\n";
    } else {
      for (int i = n; i >= n - k + 2; i--)
        a[i] = pre[i] - pre[i - 1];
      for (int i = n - k + 1; i >= 2; i--) {
        a[i] = a[i + 1];
        pre[i - 1] = pre[i] - a[i];
      }
      a[1] = pre[1];

      bool ok = 1;
      for (int i = 1; i < n; i++)
        if (a[i] > a[i + 1])
          ok = 0;
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
}