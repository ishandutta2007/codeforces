#include <bits/stdc++.h>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> friends(n, 0);
  int ans = n;
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int k = min(u, v);
    if (friends[k] == 0) {
      ans--;
    }
    friends[k]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    if (p == 3) {
      cout << ans << '\n';
    }
    else {
      int u, v;
      cin >> u >> v;
      u--, v--;
      int k = min(u, v);
      if (p == 1) {
        if (friends[k] == 0) {
          ans--;
        }
        friends[k]++;
      }
      else {
        friends[k]--;
        if (friends[k] == 0) {
          ans++;
        }
      }
    }
  }
}