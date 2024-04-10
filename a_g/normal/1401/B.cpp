#include <bits/stdc++.h>
using namespace std;


const vector<pair<int, int>> pairs = {
  {2, 1},
  {1, 1},
  {2, 2},
  {1, 0},
  {0, 2},
  {0, 1},
  {2, 0},
  {0, 0},
  {1, 2}
};

int a[3], b[3];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    int ans = 0;
    for (auto& [i, j]: pairs) {
      int d = min(a[i], b[j]);
      int c = (i+j == 3 ? 2*(i-j) : 0);
      ans += c*d;
      a[i] -= d;
      b[j] -= d;
    }
    cout << ans << '\n';
  }
}