#include <iostream>

using namespace std;

const int maxn = 300005;
const int inf = 100000005;

int x [maxn], y [maxn];

int main () {
  ios::sync_with_stdio(false);
  
  int pointc;
  cin >> pointc;

  int maxx = -inf, minx = inf;
  int maxy = -inf, miny = inf;
  for (int i = 0; i < pointc; i++) {
    cin >> x[i] >> y[i];

    maxx = max(maxx, x[i]);
    minx = min(minx, x[i]);
    maxy = max(maxy, y[i]);
    miny = min(miny, y[i]);
  }

  int anst = 0;
  for (int i = 0; i < pointc; i++) {
    int xsc = max(x[i] - minx, maxx - x[i]);
    int ysc = max(y[i] - miny, maxy - y[i]);
    anst = max(anst, 2 * (xsc + ysc));
  }
  cout << anst << " ";
  
  int perim = 2 * (maxx - minx + maxy - miny);
  for (int i = 4; i <= pointc; i++) {
    cout << perim << " ";
  }
  cout << '\n';
}