#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100;
int v[1 + nmax * nmax];
int frec[1 + nmax], seen[1 + nmax];
std::pair<int,int> sol[1 + nmax];

void solvebatch(int n, int k, int from, int to) {
  for(int i = 1;i <= n; i++)
    frec[i] = 0;
  for(int i = 1; i <= n * k; i++) {
    if(seen[v[i]] == 0 && from <= v[i] && v[i] <= to) {
      if(0 < frec[v[i]]) {
        sol[v[i]] = {frec[v[i]], i};
        seen[v[i]] = 1;
        for(int j = 1;j <= n; j++)
          frec[j] = 0;
      } else
        frec[v[i]] = i;
    }
  }
}

int main() {
  int n, k;
  std::cin >> n >> k;
  for(int i = 1; i <= n * k; i++)
    std::cin >> v[i];
  int p = k - 1;
  for(int i = 1; i <= n; i += p) 
    solvebatch(n, k, i, std::min(n, i + p - 1));

  for(int i = 1;i <= n; i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  return 0;
}