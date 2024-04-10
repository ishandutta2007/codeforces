#include <bits/stdc++.h>
using namespace std;

// I =  A-B/2+1
const int N = 6005;
int cnt[N][4][4][4];
long long ans[2];

struct pt {
  int x, y;
};

int main () {
  int n;
  cin >> n;
  vector<pt> a(n);
  for (pt& p: a) {
    cin >> p.x >> p.y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int dx = a[i].x-a[j].x;
      int dy = a[i].y-a[j].y;
      int b = __gcd(abs(dx), abs(dy))&3;
      cnt[i][(-dx)&3][(-dy)&3][b]++;
      cnt[j][dx&3][dy&3][b]++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int x1 = 0; x1 < 4; x1++) {
      for (int y1 = 0; y1 < 4; y1++) {
        for (int b1 = 0; b1 < 4; b1++) {
          if (!cnt[i][x1][y1][b1]) continue;
          // b3 should be even
          for (int x2 = x1; x2 < 4; x2+=2) {
            for (int y2 = (x1 == x2 ? y1 : (y1&1)); y2 < 4; y2+=2) {
              for (int b2 = (x1 == x2 && y1 == y2 ? b1 : (b1&1)); b2 < 4; b2+=2) {
                if (!cnt[i][x2][y2][b2]) continue;
                int b3 = (x1 == x2 && y1 == y2 ? 0 : 2);
                int A = abs(x1*y2-x2*y1)/2;
                if ((A+(b1+b2+b3)/2)&1) continue;
                int c1 = cnt[i][x1][y1][b1];
                int c2 = cnt[i][x2][y2][b2];
                if (x1 == x2 && y1 == y2 && b1 == b2) {
                  ans[b1&1] += 1LL*c1*(c1-1)/2;
                }
                else {
                  ans[b1&1] += 1LL*c1*c2;
                }
              }
            }
          }
        }
      }
    }
  }

  assert(ans[0]%3 == 0);
  cout << ans[0]/3+ans[1] << '\n';
}