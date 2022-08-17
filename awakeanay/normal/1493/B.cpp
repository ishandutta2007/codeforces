#include <iostream>
#include <iomanip>

int x, y;
int h, m;

int rot[10] = {0, 1, 5, 100, 100, 2, 100, 100, 8, 100};

int mir(int x) {
  return (rot[(x/10)] + rot[(x%10)]*10);
}

bool check() {
  int nx, ny;
  ny = mir(x);
  nx = mir(y);

  return (nx < h && ny < m);
}

void add() {
  y++;
  if(y == m) {
    y = 0;
    x++;
    if(x == h)
      x = 0;
  }
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> h >> m;

    x = y = 0;
    char p, q, r, s;
    std::cin >> p >> q >> r >> r >> s;
    x = (p-'0')*10 + (q-'0');
    y = (r-'0')*10 + (s-'0');

    while(!check())
      add();

    std::cout << std::setw(2) << std::setfill('0') << x;
    std::cout << ":";
    std::cout << std::setw(2) << std::setfill('0') << y;
    std::cout << std::endl;
  }

  return 0;
}