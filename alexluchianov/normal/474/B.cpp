#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 100000;
int const valmax = 1000000;
int v[1 + nmax], group[1 + valmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int ptr = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1;j <= v[i]; j++)
      group[++ptr] = i;

  int m;
  std::cin >> m;
  for(int i = 1;i <= m; i++) {
    int target;
    std::cin >> target;
    std::cout << group[target] << '\n';
  }
  return 0;
}