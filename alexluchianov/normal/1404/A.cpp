#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
char v[1 + nmax];

void solve() {
  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int balance = 0, undecided = 0;
  for(int i = 1; i <= k; i++) {
    int type = 0;
    for(int j = i; j <= n; j += k)
      if(v[j] == '1')
        type |= 1;
      else if(v[j] == '0')
        type |= 2;
    if(type == 3) {
      std::cout << "NO\n";
      return ;
    }
    if(type == 0)
      undecided++;
    else if(type == 1)
      balance++;
    else
      balance--;
  }
  if(fabs(balance) <= undecided)
    std::cout << "YES\n";
  else
    std::cout << "NO\n";
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}