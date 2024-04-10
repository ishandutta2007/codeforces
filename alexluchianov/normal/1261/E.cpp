#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int v[1 + nmax], p[1 + nmax];
std::string sol[5 + nmax];

std::pair<int,int> bonus[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  for(int i = 0; i < n; i++)
    bonus[i] = {v[i], i};
  std::sort(bonus, bonus + n);
  std::reverse(bonus, bonus + n);

  for(int i = 0; i < n; i++)
    p[bonus[i].second] = i;

  for(int i = 0; i <= n; i++) {
    sol[i].resize(n);
    for(int j = 0; j < n; j++)
      sol[i][j] = '0';
  }
    
  for(int i = 0; i < n; i++)
    for(int j = 0; j < v[i]; j++)
      sol[(p[i] + j) % (n + 1)][i] = '1';
  std::cout << n + 1 << '\n';
  for(int i = 0; i <= n; i++)
    std::cout << sol[i] << '\n';
  return 0;
}