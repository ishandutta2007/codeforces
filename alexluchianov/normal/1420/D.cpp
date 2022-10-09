#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const modulo = 998244353;
int fact[1 + nmax];

void computefact() {
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++) 
    fact[i] = 1LL * fact[i - 1] * i % modulo;
}

void gcd(int a, int b, int &x, int &y) {
  if(b == 0) {
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a/ b * y;
  }
}

int inv(int number) {
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x; 
}

int comb(int n, int k) {
  if(0 <= k && k <= n) {
    int result = fact[n];
    int result2 = 1LL * fact[k] * fact[n - k] % modulo;
    return 1LL * result * inv(result2) % modulo;
  } else
    return 0;
}

std::pair<int,int> v[1 + nmax];

void normalize(int n) {
  std::vector<int> aux;
  for(int i = 1;i <= n; i++) {
    aux.push_back(v[i].first);
    aux.push_back(v[i].second);
  }
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  std::map<int,int> mp;
  for(int i = 0; i < aux.size(); i++)
    mp[aux[i]] = 1 + i;
  for(int i = 1; i <= n; i++)
    v[i] = {mp[v[i].first], mp[v[i].second]};
}

class FenwickTree{
  private:
    std::vector<int> aib;
    int n;
  public:
    FenwickTree(int n_) {
      n = n_;
      aib.resize(1 + n);
    }
    void update(int pos, int val) {
      for(int x = pos; x <= n; x += ((x & (x - 1)) ^ x))
        aib[x] += val;
    }
    int query(int pos) {
      int result = 0;
      for(int x = pos; 0 < x; x = (x & (x - 1)))
        result += aib[x];
      return result;
    }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i].first >> v[i].second;
  std::sort(v + 1, v + n + 1);
  normalize(n);
  FenwickTree aib(2 * n);
  ll result = 0;
  computefact();

  for(int i = 1;i <= n; i++) {
    result += comb(i - 1 - aib.query(v[i].first - 1), k - 1);
    if(modulo <= result)
      result -= modulo;
    aib.update(v[i].second, 1);
  }
  std::cout << result;
  return 0;
}