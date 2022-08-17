#include <iostream>

#define MAXA 10000001

int lp[MAXA];

signed main() {
  std::ios::sync_with_stdio(false);

  for(int i = 2; i < MAXA; i++) {
    if(lp[i])
      continue;

    for(int j = i; j < MAXA; j += i) {
      lp[j] = i;
    }
  }

  int n;
  std::cin >> n;

  int d1[n], d2[n];

  for(int i = 0; i < n; i++) {
    int a;
    std::cin >> a;

    int p = lp[a];
    int a1 = 1;

    while(a % p == 0) {
      a1 *= p;
      a /= p;
    }

    if(a == 1)
      d1[i] = d2[i] = -1;
    else
      d1[i] = a1, d2[i] = a;
  }

  for(int i = 0; i < n; i++)
    std::cout << d1[i] << " ";
  std::cout << std::endl;
  for(int i = 0; i < n; i++)
    std::cout << d2[i] << " ";
  std::cout << std::endl;

  return 0;
}