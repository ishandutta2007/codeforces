#include <iostream>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;

struct Point{
  int x;
  int y;
} v[1 + nmax];

ll mksqr(ll val) {
  return val * val;
}

ll dist(Point a, Point b) {
  return mksqr(a.x - b.x) + mksqr(a.y - b.y);
}
int seen[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i].x >> v[i].y;
  
  int last = 1;
  seen[1] = 1;
  std::cout << 1 << " ";

  for(int i = 1; i < n; i++) {
    int id = 0;
    ll smax = 0;
    for(int j = 1;j <= n; j++)
      if(seen[j] == 0 && smax < dist(v[last], v[j])) {
        smax = dist(v[last], v[j]);
        id = j;
      }

    seen[id] = 1;
    std::cout << id << " ";
    last = id;
  }
  std::cout << '\n';
  return 0;
}