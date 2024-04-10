#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    int max_red = 0, max_white = 0;
    for (int i = 1; i <= m; ++i) {
      int r, w;
      cin >> r >> w;
      max_red = max(max_red, r);
      max_white = max(max_white, w);
    }

    if (max_red + max_white > n) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    string ans = "";
    while (max_red--) {
      ans.push_back('R');
    }
    while (max_white--) {
      ans.push_back('W');
    }
    while ((int)ans.size() < n) {
      ans.push_back('W');
    }
    cout << ans << '\n';
  }

  return 0;
}