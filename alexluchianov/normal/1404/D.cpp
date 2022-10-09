#include <iostream>
#include <vector>
#include <cassert>
#include <bitset>


using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int v[1 + nmax], sum[1 + nmax];
int used[1 + nmax];
int n;
int oth(int val) {
  if(val <= n)
    return val + n;
  else
    return val - n;
}

int main() {
  std::cin >> n;
  if(n % 2 == 0) {
    std::cout << "First\n";
    for(int i = 1;i <= 2 * n; i++)
      std::cout << (i - 1) % n + 1 << " ";
    std::cout << '\n' << std::flush;
  } else {
    std::cout << "Second\n";
    std::cout << std::flush;
    for(int i = 1;i <= 2 * n; i++) {
      std::cin >> v[i];
      sum[v[i]] += i;
    }
    std::vector<int> sol;
    for(int i = 1;i <= n; i++) {
      int node = i;
      while(used[v[node]] == 0) {
        used[v[node]] = 1;
        sol.push_back(node);
        node = sum[v[oth(node)]] - oth(node);
      }
    }
    ll result = 0;
    for(int i = 0; i < sol.size(); i++)
      result += sol[i];
    if(result % (2 * n) == 0)
      for(int i = 0; i < sol.size(); i++)
        std::cout << sol[i] << " ";
    else
      for(int i = 0; i < sol.size(); i++)
        std::cout << sum[v[sol[i]]] - sol[i] << " ";
    std::cout << std::flush;
  }
  return 0;
}