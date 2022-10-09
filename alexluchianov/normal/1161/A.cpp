#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int frec[1 + nmax], frec2[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= k; i++) {
    int x;
    std::cin >> x;
    if(frec[x] == 0) 
      frec[x] = frec2[x] = i;
    else
      frec2[x] = i;
  }
  int result = 0;
  for(int i = 1;i <= n; i++)
    if(0 == frec[i])
      result++;
  for(int i = 2;i <= n; i++)
    if(frec[i] == 0 || frec2[i - 1] < frec[i])
      result++;
  for(int i = 1;i < n; i++)
    if(frec[i] == 0 || frec2[i + 1] < frec[i])
      result++;
  std::cout << result;
  return 0;
}