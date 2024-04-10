#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> d(n, 0);
    for (int &e : a) cin >> e;
    int sum = 0;
    for (int e : a) sum += e;
    if (sum == x) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> res;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[j]) continue;
        if (a[j] != x - cur) {
          cur += a[j];
          d[j] = 1;
          res.push_back(j);
          break;
        }
      }
    }
    for (int e : res) cout << a[e] << ' ';
    cout << '\n';
  }

  return 0;
}