#include <bits/stdc++.h>

using namespace std;

const int M = 100100;
typedef long long ll;

struct Point {
  ll x, y;

  Point(): x(0), y(0) { }
  Point(int x, int y): x(x), y(y) { }

  Point operator-(Point to) { return Point(x - to.x, y - to.y);}

  ll operator*(Point to) { return x * to.y - y * to.x;}

  ll abs() {
    return x * x + y * y;
  }
};

int n;
int x = 1;
Point p[M];

ll mabs(ll x) {
  return x < 0 ? -x : x;
}

ll area(int y) {
  return mabs((p[y] - p[x]) * (p[y] - p[0]));
}


void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> p[i].x >> p[i].y;

  for (int i = 1; i < n; ++i)
    if ((p[i] - p[0]).abs() < (p[x] - p[0]).abs())
      x = i;

  int mn = -1;
  for (int j = 1; j < n; ++j)
    if (area(j) > 0)
      mn = j;

  assert(mn != -1);

  for (int j = 1; j < n; ++j)
    if (area(j) < area(mn) && area(j) > 0)
      mn = j;
  
  cout << "1 " << x + 1 << " " << mn + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
}