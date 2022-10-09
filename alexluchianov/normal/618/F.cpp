#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
ll a[5 + nmax], b[5 + nmax];
int frec[5 + nmax][2];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> a[i];
  for(int i = 1;i <= n; i++)
    std::cin >> b[i];
  for(int i = 1;i <= n; i++)
    a[i] += a[i - 1];
  for(int i = 1;i <= n; i++)
    b[i] += b[i - 1];
  int swup = 0;
  if(a[n] < b[n]) { 
    swup = 1;
    for(int i = 1; i <= n; i++)
      std::swap(a[i], b[i]);
  }

  int ptr = 0;
  a[n + 1] = b[n] + 5;
  for(int i = 0 ; i <= n; i++)
    frec[i][0] = -1;

  for(int i = 0;i <= n; i++) {
    while(a[ptr + 1] <= b[i])
      ptr++;
    int dif = b[i] - a[ptr];
    if(frec[dif][0] < 0) {
      frec[dif][0] = ptr;
      frec[dif][1] = i;
    } else {
      if(swup == 0) {
        std::cout << ptr - frec[dif][0] << '\n';
        for(int j = frec[dif][0] + 1; j <= ptr; j++)
          std::cout << j << " ";
        std::cout << '\n';
        std::cout << i - frec[dif][1] << '\n';
        for(int j = frec[dif][1] + 1; j <= i; j++)
          std::cout << j << " ";
        std::cout << '\n';
      } else {
        std::cout << i - frec[dif][1] << '\n';
        for(int j = frec[dif][1] + 1; j <= i; j++)
          std::cout << j << " ";
        std::cout << '\n';
      
        std::cout << ptr - frec[dif][0] << '\n';
        for(int j = frec[dif][0] + 1; j <= ptr; j++)
          std::cout << j << " ";
        std::cout << '\n';
      }
      return 0;
    }
  }
  return 0;
}