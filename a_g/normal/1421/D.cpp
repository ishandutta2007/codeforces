#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;
int c[7];
int d[7][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  d[1][0] = 1;
  d[1][1] = 1;
  d[2][1] = 1;
  d[3][0] = -1;

  d[4][0] = -1;
  d[4][1] = -1;
  d[5][1] = -1;
  d[6][0] = 1;

  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= 6; i++) cin >> c[i];
    long long ans = INF;
    for (int i = 1; i <= 6; i++) {
      for (int j = i+1; j <= 6; j++) {
        if (j == i+3) continue;
        // a*d[i][0]+b*d[j][0] = x
        // a*d[i][1]+b*d[j][1] = y
        int a = (x*d[j][1]-y*d[j][0])/(d[i][0]*d[j][1]-d[i][1]*d[j][0]);
        int b = -(x*d[i][1]-y*d[i][0])/(d[i][0]*d[j][1]-d[i][1]*d[j][0]);
        if (a >= 0 && b >= 0) {
          ans = min(ans, 1LL*a*c[i]+1LL*b*c[j]);
        }
      }
    }
    cout << ans << '\n';
  }
}