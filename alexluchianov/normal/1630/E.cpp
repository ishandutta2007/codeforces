#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

const int nmax = 1000000;
const int modulo = 998244353;

int v[5 + nmax], frec[5 + nmax];
int dp[5 + nmax], total[5 + nmax];
int fact[5 + nmax], invfact[5 + nmax];

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

void precompute() {
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  invfact[nmax] = inverse(fact[nmax]);
  for(int i = nmax; 1 <= i; i--)
    invfact[i - 1] = 1LL * invfact[i] * i % modulo;
}

std::vector<int> active;

void explore(int n, int k) {
  int lim = n / k;
  int result = 0;
  int base = 1;
  for(int i = 0; i < active.size(); i++) {
    int val = frec[active[i]] / k;
    base = 1LL * base * invfact[val] % modulo;
  }
  for(int i = 0; i < active.size(); i++) {
    int val = frec[active[i]] / k;
    if(1 < val) {
      int sec = 1LL * base * val % modulo * (val - 1) % modulo;
      result = (result + 1LL * sec * fact[lim - 2] % modulo * lim % modulo * k) % modulo;
    }
  }
  dp[k] = result;
  total[k] = 1LL * base * fact[lim] % modulo;
}

int solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    frec[i] = 0;

  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    frec[v[i]]++;
  }

  bool allEqual = true;
  for(int i = 2;i <= n; i++)
    allEqual &= (v[i - 1] == v[i]);
  if(allEqual)
    return 1;
  
  int target = 0;
  active.clear();
  for(int i = 1;i <= n; i++)
    if(0 < frec[i]) {
      target = std::__gcd(target, frec[i]);
      active.push_back(i);
    }

  for(int i = n; 1 <= i; i--)
    if(target % i == 0) {
      explore(n, i);
    } else
      dp[i] = total[i] = 0;

  int allDp = 0, alltotal = 0;

  for(int i = n; 1 <= i; i--) {
    for(int j = 2 * i; j <= n; j += i) {
      dp[i] -= dp[j];
      if(dp[i] < 0)
        dp[i] += modulo;
      total[i] -= total[j];
      if(total[i] < 0)
        total[i] += modulo;
    }

    allDp = (allDp + 1LL * dp[i] * inverse(n / i)) % modulo;
    alltotal = (alltotal + 1LL * total[i] * inverse(n / i)) % modulo;
  }

  return (modulo + n - (1LL * allDp * inverse(alltotal) % modulo)) % modulo;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);


  precompute();
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
  return 0;
}