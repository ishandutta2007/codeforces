#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<pair<int, int>> corners;
    int x = 1;
    int y = 1;
    char dir = 'Z';
    for (char c: s) {
      if (c != dir) {
        corners.emplace_back(x, y);
        dir = c;
      }
      if (dir == 'R') x++;
      else y++;
    }
    corners.emplace_back(x, y);
    //reverse(corners.begin(), corners.end());
    int m = corners.size();
    if (m <= 2) {
      cout << n << '\n';
      continue;
    }
    int kx = n+1-corners.back().first;
    int ky = n+1-corners.back().second;
    long long ans = 1LL*kx*ky;
    for (int j = m-2; j >= 1; j--) {
      ans += 1LL * ky * (corners[j+1].first-corners[j].first) +
        1LL * kx * (corners[j+1].second-corners[j].second);
    }
    ans += (corners[1].first - corners[0].first) + (corners[1].second - corners[0].second);
    cout << ans << '\n';
  }
}