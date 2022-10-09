#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;

int const nmax = 500000;
int const modulo = 998244353;
int fact[1 + nmax];

void gcd(int a, int b, int &x, int &y) {
  if(b == 0) {
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int inverse(int number) {
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

int comb(int n, int k) {
  if(0 <= k && k <= n) {
    return 1LL * fact[n] *
    inverse(1LL * fact[k] * fact[n - k] % modulo) % modulo;
  } else
    return 0;
}

void precompute() {
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;
}

int aib[1 + nmax];

void update(int pos, int val) {
  for(int x = pos; x <= nmax; x += (x ^ (x & (x - 1))))
    aib[x] += val;
}

int query(int pos) {
  int result = 0;
  for(int x = pos; 0 < x; x = (x & (x - 1)))
    result += aib[x];
  return result;
}

int findtarget(int target) {
  int x = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2)
    if(x + jump <= nmax && aib[x + jump] < target) {
      x += jump;
      target -= aib[x];
    }
  return x + 1;
}

std::map<int, int> mp;

int solve() {
  int n, m;
  std::cin >> n >> m;

  int barriers = n - m - 1;
  std::vector<std::pair<int,int>> events;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    events.push_back({x, y});
  }
  mp.clear();

  for(int i = events.size() - 1; 0 <= i; i--) {
    int pos = findtarget(events[i].second);
    if(mp.find(pos + 1) != mp.end())
      barriers += 1;
    mp[pos] = 1;
    update(pos, -1);
  }
  for(std::map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) {
    update(it->first, 1);
  }
  return comb(n + barriers, barriers);
}

int main() {
  precompute();
  for(int i = 1; i <= nmax; i++)
    update(i, 1);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::cout << solve() << '\n';
  }
}