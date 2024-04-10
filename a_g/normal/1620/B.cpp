#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  return abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int w, h;
    cin >> w >> h;
    vector<vector<int>> pts(4);
    // bottom, top, left, right
    for (int i = 0 ; i < 4; i++) {
      int k;
      cin >> k;
      pts[i].resize(k);
      for (int j = 0; j < k; j++) {
        cin >> pts[i][j];
      }
    }
    ll ans = 0;
    ans = max(ans, 1LL*h*(pts[0].back() - pts[0][0]));
    ans = max(ans, 1LL*h*(pts[1].back() - pts[1][0]));
    ans = max(ans, 1LL*w*(pts[2].back() - pts[2][0]));
    ans = max(ans, 1LL*w*(pts[3].back() - pts[3][0]));
    cout << ans << '\n';
  }
}