#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;
const int INF = 1e9 + 5;

int n, lx[N], ly[N], rx[N], ry[N];
int suflx[N], sufly[N], sufrx[N], sufry[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d", lx + i, ly + i, rx + i, ry + i);
  }
  suflx[n + 1] = sufly[n + 1] = -INF;
  sufrx[n + 1] = sufry[n + 1] = +INF;
  for (int i = n; i >= 1; --i) {
    suflx[i] = max(suflx[i + 1], lx[i]);
    sufly[i] = max(sufly[i + 1], ly[i]);
    sufrx[i] = min(sufrx[i + 1], rx[i]);
    sufry[i] = min(sufry[i + 1], ry[i]);
  }
  int prelx = -INF, prely = -INF, prerx = INF, prery = INF;
  for (int i = 1; i <= n; ++i) {
    int px = max(prelx, suflx[i + 1]);
    int py = max(prely, sufly[i + 1]);
    int qx = min(prerx, sufrx[i + 1]);
    int qy = min(prery, sufry[i + 1]);
    if (px <= qx and py <= qy) {
      cout << px << " " << py << '\n';
      return 0;
    }
    prelx = max(prelx, lx[i]);
    prely = max(prely, ly[i]);
    prerx = min(prerx, rx[i]);
    prery = min(prery, ry[i]);
  }
  assert(false);
  return 0;
}