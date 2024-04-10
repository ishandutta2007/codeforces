#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    vector<pair<int, int>> pts(3);
    int ans = 0;
    for (int i = 0; i < 3; i++) {
      cin >> pts[i].first >> pts[i].second;
    }
    for (int i = 0; i < 3; i++) {
      for (int j = i+1; j < 3; j++) {
        if (pts[i].second == pts[j].second && pts[(3-i-j)%3].second < pts[i].second) {
          ans += abs(pts[i].first-pts[j].first);
        }
      }
    }
    cout << ans << '\n';
  }
}