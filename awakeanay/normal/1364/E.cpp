#include <iostream>
#include <vector>
#include <random>

#define MAXN 2060

int qdone;
std::vector<std::vector<int> > store(MAXN, std::vector<int>(MAXN, -1));
int n;

int query(int x, int y) {
  if(store[x][y] != -1)
    return store[x][y];

  std::cout << "? " << x << " " << y << std::endl;
  qdone++;
  int ret;
  std::cin >> ret;
  //ret = (x-1) | (y-1);
  store[x][y] = store[y][x] = ret;
  return ret;
}

signed main() {
  std::cin >> n;

  int x = 1, y = 2;
  int xory = query(1, 2);

  for(int i = 3; i <= n; i++) {
    int nor = query(y, i);

    if(nor > xory)
      continue;

    if(nor < xory) {
      x = i;
      xory = nor;
      continue;
    }

    y = i;
    xory = query(x, y);
  }

  srand(3242234324);
  int zero = y;
  for(int i = 0; i < 5000; i++) {
    if(qdone + n >= 4268)
      break;

    int next = rand()%n + 1;
    if(next == x || next == y)
      continue;

    if((xory & query(x, next)) != xory) {
      zero = x;
    }
  }

  int ans[n+1];
  for(int i = 1; i <= n; i++) {
    if(zero == i) {
      ans[i] = 0;
      continue;
    }
    ans[i] = query(zero, i);
  }

  std::cout << "! ";
  for(int i = 1; i <= n; i++)
    std::cout << ans[i] << " ";
  std::cout << std::endl;
  return 0;
}