#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using ll = long long;
using ld = long double;

int const nmax = 1000;
ld const eps = 0.0000001;
int const inf = 1000000000;
int const prec = 60;

int x[1 + nmax], b[1 + nmax];
int n, l;

ld dp[1 + nmax];
int last[1 + nmax];

bool check(ld target) {
  for(int i = 1; i <= n; i++) {
    dp[i] = -inf;
    last[i] = i - 1;
    for(int j = 0; j < i; j++) {
      ld newcost = dp[j] - sqrt(std::fabs(x[i] - x[j] - l)) + b[i] * target;
      if(dp[i] < newcost) {
        dp[i] = newcost;
        last[i] = j;
      }
    }
  }

  return 0 <= dp[n];
}

void print(int node) {
  if(0 < last[node])
    print(last[node]);
  std::cout << node << " ";
}

int main() {
  std::cin >> n >> l;
  for(int i = 1;i <= n; i++)
    std::cin >> x[i] >> b[i];
  ld start = eps, stop = inf;
  for(int i = 0; i < prec; i++) {
    ld mid = (start + stop) / 2;
    if(check(mid) == 1)
      stop = mid;
    else
      start = mid;
  }
  check(stop);
  print(n);
  std::cout << '\n';
  return 0;
}