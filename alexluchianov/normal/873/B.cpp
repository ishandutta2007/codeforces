#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int frec[1 + nmax * 2];
char ch[1 + nmax];
int sum[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> ch[i];
  for(int i = 0; i <= 2 * n; i++)
    frec[i] = nmax;

  sum[0] = n;

  for(int i = 1;i <= n; i++)
    if(ch[i] == '0')
      sum[i] = sum[i - 1] - 1;
    else
      sum[i] = sum[i - 1] + 1;
  frec[sum[0]] = 0;
  int result = 0;
  for(int i = 1;i <= n; i++) {
    result = std::max(result, i - frec[sum[i]]);
    frec[sum[i]] = std::min(frec[sum[i]], i);
  }
  std::cout << result;
  return 0;
}