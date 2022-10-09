#include <iostream>
#include <vector>
#include <set>

using ll = long long;

int modulo;

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

std::set<int> myset;

bool check(int n, int start, int r) {
  int curr = start, curr2 = start;
  int checkright = n - 1, checkleft = modulo - n;
  while(0 < checkright && 0 < checkleft) {
    if(0 < checkright) {
      curr = (curr + r) % modulo;
      if(myset.find(curr) == myset.end())
        return false;
      checkright--;
    }
    if(0 < checkleft) {
      curr2 = (modulo + curr2 -r) % modulo;
      if(myset.find(curr2) != myset.end())
        return false;
      checkleft--;
    }
  }
  return true;
}
int const nmax = 100000;
int v[5 + nmax];
int main() {
  int n;
  std::cin >> modulo >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    myset.insert(v[i]);
    sum += v[i];
    if(modulo <= sum)
      sum -= modulo;
  }
  if(n == 1) {
    std::cout << v[1] << " " << 0 << '\n';
    return 0;
  } else if(n == modulo) {
    std::cout << 0 << " " << 1 << '\n';
    return 0;
  }

  for(int i = 1; i <= n; i++) {
    int start = v[i];
    int r = (sum - 1LL * start * n) % modulo;
    if(r < 0)
      r += modulo;
    if(n + 1 == modulo)
      r = 1;
    else
      r = 1LL * r * inverse(1LL * n * (n - 1) / 2 % modulo) % modulo;
    if(check(n, start, r) == 1) {
      std::cout << start << " " << r << '\n';
      return 0;
    }
  }

  std::cout << -1 << '\n';
  return 0;
}