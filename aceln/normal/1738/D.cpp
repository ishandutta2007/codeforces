#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n + 2), a(n + 2);
    vector<vector<int>> bb(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      bb[b[i]].emplace_back(i);
    }

    vector<vector<int>> v(n + 2);
    v[0] = {0, n + 1};

    int idx = 1;
    for (int i = 0;; i++) {
      bool found = 0;
      for (int j : v[i]) {
        if (!bb[j].empty()) {
          found = 1;
          v[i + 1] = bb[j];
          if (i == 0)
            continue;

          for (int k : v[i])
            if (k != j)
              a[idx++] = k;
          a[idx++] = j;
          break;
        }
      }
      if (!found) {
        for (int j : v[i])
          a[idx++] = j;
        break;
      }
    }

    int k = 0;
    for (int i = 1; i <= n; i++)
      if (b[a[i]] >= a[i])
        k = max(k, a[i]);
    cout << k << '\n';
    for (int i = 1; i <= n; i++)
      cout << a[i] << " \n"[i == n];
  }
}