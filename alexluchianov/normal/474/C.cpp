#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 4;
int x[nmax], y[nmax], a[nmax], b[nmax];

void rotate(int id) {
  int xdif = x[id] - a[id];
  int ydif = y[id] - b[id];
  x[id] = -ydif + a[id];
  y[id] = xdif + b[id];
}

int dist(int a1, int a2) {
  return (x[a1] - x[a2]) * (x[a1] - x[a2]) + (y[a1] - y[a2]) * (y[a1] - y[a2]);
}

bool check2(int a1, int a2, int a3, int a4) {
  return 0 < dist(a1, a2) && 0 < dist(a1, a3) &&
         dist(a1, a2) == dist(a2, a3) && dist(a2, a3) == dist(a3, a4) &&
         dist(a3, a4) == dist(a4, a1) && dist(a1, a3) == dist(a2, a4);
}

bool check() {
  for(int i = 1;i < 4; i++)
    for(int j = 1; j < 4; j++)
      if(i != j)
        for(int h = 1; h < 4; h++)
          if(i != h && j != h)
            if(check2(0, i, j, h) == 1)
              return 1;
  return 0;
}

int solve() {
  for(int i = 0; i < nmax; i++)
    std::cin >> x[i] >> y[i] >> a[i] >> b[i];
  int result = nmax * 4 + 1;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      for(int h = 0; h < 4; h++) {
        for(int h2 = 0; h2 < 4; h2++) {
          if(check() == 1) 
            result = std::min(result, i + j + h + h2);
          rotate(3);
        }
        rotate(2);
      }
      rotate(1);
    }
    rotate(0);
  }
  if(result == nmax * 4 + 1)
    return -1;
  else
    return result;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cout << solve() << '\n';
  }
  return 0;
}