#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll v[1 + nmax], pref[1 + nmax], suff[1 + nmax];

int main() {
  int n, d, m;
  std::cin >> n >> d >> m;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::sort(v + 1, v + n + 1);
  int lim = 0;
  for(int i = 1;i <= n; i++)
    if(v[i] <= m)
      lim = i;
  std::reverse(v + 1, v + lim + 1);
  for(int i = 1;i <= n; i++)
    pref[i] = pref[i - 1] + v[i];
  for(int i = n; 1 <= i; i--)
    suff[i] = suff[i + 1] + v[i];
  ll result = 0;
   
  for(int i = 1;i <= n; i++){
    int block = i + (i - 1) * d;
    if(0 <= n - block)
      result = std::max(result, pref[std::min(lim, n - block)] + suff[n - i + 1]);
    else
      break;
  }
  std::cout << result;
  return 0;
}