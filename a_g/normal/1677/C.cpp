#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    vector<bool> vis(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    for (int& x: a) x--;
    for (int& x: b) x--;
    for (int i = 0; i < n; i++) {
      p[a[i]] = b[i];
    }

    int oddcyc = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      int len = 0;
      int v = i;
      while (!vis[v]) {
        vis[v] = 1;
        len++;
        v = p[v];
      }
      if (len&1) oddcyc++;
    }
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
      vals[i] = abs(2*i-(n-1));
    }
    sort(vals.begin(), vals.end());
    cout << accumulate(vals.begin()+oddcyc, vals.end(), 0LL) << '\n';
  }
}