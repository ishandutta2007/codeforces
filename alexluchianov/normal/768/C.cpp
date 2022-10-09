#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 1024;
int frec[1 + nmax];
int frec2[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k, x;
  std::cin >> n >> k >> x;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    frec[val]++;
  }
  for(int _step = 1; _step <= k; _step++) {
    int ptr = 0;
    for(int j = 0; j < nmax; j++) {
      frec2[j] += frec[j] / 2;
      frec2[j ^ x] += frec[j] / 2;
      frec[j] &= 1;
      if(ptr == 0) {
        frec2[j ^ x] += frec[j];
        ptr ^= frec[j];
      } else if(ptr == 1) {
        frec2[j] += frec[j];
        ptr ^= frec[j];
      }
    }
    for(int j = 0; j < nmax; j++) {
      frec[j] = frec2[j];
      frec2[j] = 0;
    }
  }

  int smin = nmax, smax = 0;
  for(int i = 0; i <= nmax; i++)
    if(0 < frec[i]) {
      smax = std::max(smax, i);
      smin = std::min(smin, i);
    }
  std::cout << smax << " " << smin;
  return 0;
}