#include <iostream>
#include <vector>

using ll = long long;

ll solve(ll n, ll l, ll r) {
  ll result = 0;
  ll n2 = n;
  while(1 < n2) {
    result++;
    n2 /= 2;
  }
  result = (1LL << (result)) - 1;
  ll sol = 0;

  if(l <= result) 
    sol += solve(n / 2, l, std::min(result, r));
  if(result + 1 < r)
    sol += solve(n / 2, std::max(l, result + 2) - result - 1, r - result - 1);
  if(l <= result + 1 && result + 1 <= r)
    sol += n % 2;
  return sol;
}

int main() {
  ll n, l, r;
  std::cin >> n >> l >> r;
  std::cout << solve(n, l, r);
  return 0;
}