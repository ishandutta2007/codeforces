#include <bits/stdc++.h>
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int W, H;
    cin >> W >> H;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    if (w+x2-x1 > W && h+y2-y1 > H) {
      cout << -1 << endl;
    }
    else {
       int d = W+H;
       if (w+x2-x1 <= W) {
         int a = max(w-x1, 0);
         int b = max(w+x2-W, 0);
         d = min(d, a);
         d = min(d, b);
       }
       if (h+y2-y1 <= H) {
         int a = max(h-y1, 0);
         int b = max(h+y2-H, 0);
         d = min(d, a);
         d = min(d, b);
       }
       cout << d << endl;
    }
  }
}