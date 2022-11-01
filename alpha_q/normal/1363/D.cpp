#include <bits/stdc++.h>

using namespace std;

string cor;
int t, n, k, ans[6969];
vector <int> st[6969];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
      int sz; cin >> sz;
      st[i].resize(sz);
      for (auto &it : st[i]) cin >> it;
    }
    cout << "? " << n;
    for (int i = 1; i <= n; ++i) cout << " " << i;
    cout << endl;
    int mx; cin >> mx;
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = lo + hi >> 1;
      cout << "? " << mid;
      for (int i = 1; i <= mid; ++i) cout << " " << i;
      cout << endl;
      int rep; cin >> rep;
      if (rep == mx) hi = mid;
      else lo = mid + 1;
    }
    for (int i = 1; i <= k; ++i) {
      ans[i] = mx;
    }
    for (int i = 0; i < k; ++i) {
      bool ok = 0;
      for (int x : st[i]) if (x == lo) {
        ok = 1; break;
      }
      if (!ok) continue;
      vector <bool> yo(n + 7, 1);
      for (int x : st[i]) yo[x] = 0;
      int sz = n - st[i].size();
      cout << "? " << sz;
      for (int j = 1; j <= n; ++j) if (yo[j]) cout << " " << j;
      cout << endl;
      int rep; cin >> rep;
      ans[i + 1] = rep;
      break;
    }
    cout << "!";
    for (int i = 1; i <= k; ++i) cout << " " << ans[i];
    cout << endl;
    cin >> cor;
  }
  return 0;
}