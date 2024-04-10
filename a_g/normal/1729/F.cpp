#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int w, q;
    cin >> w >> q;
    vector<int> sums(n+1);
    for (int i = 0; i < n; i++) {
      sums[i+1] = sums[i] + s[i]-'0';
    }
    vector<int> borders(9, INF);
    vector<int> second_borders(9, INF);
    for (int i = n-w; i >= 0; i--) {
      int v = (sums[i+w]-sums[i])%9;
      borders[v] = i+1;
    }
    for (int i = n-w; i >= 0; i--) {
      int v = (sums[i+w]-sums[i])%9;
      if (i+1 > borders[v]) second_borders[v] = i+1;
    }

    while (q--) {
      int l, r, k;
      cin >> l >> r >> k;
      int v = sums[r]-sums[l-1];
      pair<int, int> ans = make_pair(1e9, 1e9);
      for (int i = 0; i < 9; i++) {
        if (borders[i] == INF) continue;
        for (int j = 0; j < 9; j++) {
          if (borders[j] == INF) continue;
          if ((i*v+j)%9 == k) {
            if (i != j) {
              ans = min(ans, make_pair(borders[i], borders[j]));
            }
            else if (second_borders[j] != INF) {
              ans = min(ans, make_pair(borders[i], second_borders[j]));
            }
          }
        }
      }
      if (ans.first == INF) ans = make_pair(-1, -1);
      cout << ans.first << ' ' << ans.second << '\n';
    }
  }
}