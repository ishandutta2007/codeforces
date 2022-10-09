#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 100000;
int modulo;
int v[5 + nmax];

class SegmentTree{
private:
  std::vector<int> aint;
  std::vector<int> lazy;
public:
  SegmentTree(int n = 0) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to) {
    if(from < to) {
      lazy[node * 2] = 1LL * lazy[node * 2] * lazy[node] % modulo;
      lazy[node * 2 + 1] = 1LL * lazy[node * 2 + 1] * lazy[node] % modulo;
    }
    aint[node] = 1LL* aint[node] * lazy[node] % modulo;
    lazy[node] = 1;
  }

  void build(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = (aint[node * 2] + aint[node * 2 + 1]) % modulo;
    } else
      aint[node] = v[from];
    lazy[node] = 1;
  }
  void update(int node, int from, int to, int x, int y, int val) {
    if(from == x && to == y) {
      lazy[node] = (1LL * lazy[node] * val) % modulo;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
      aint[node] = (aint[node * 2] + aint[node * 2 + 1]) % modulo;
    }
  }
  void setvalue(int node, int from, int to, int x, int val) {
    cleannode(node, from, to);
    if(from < to) {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        setvalue(node * 2, from, mid, x, val);
      else
        setvalue(node * 2 + 1, mid + 1, to, x, val);

      aint[node] = (aint[node * 2] + aint[node * 2 + 1]) % modulo;
    } else
      aint[node] = val;
  }
  int query(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x&& mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return (query(node * 2, from, mid, x, std::min(y, mid)) + 
               query(node * 2 + 1, mid + 1 , to, std::max(mid + 1, x), y))% modulo;
    }
  }
};

class FenwickTree{
private:
  std::vector<int> aib;
  int n;
public:
  FenwickTree(int n_ = 0) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1)))) {
      aib[x] += val;
    }
  }

  int query(int pos) {
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1))) {
      result += aib[x];
    }
    return result;
  }
};

std::vector<std::pair<int,int>> decompose(int number) {
  std::vector<std::pair<int,int>> sol;
  for(int i = 2; i * i <= number; i++) {
    if(number % i == 0) {
      int coef = 0;
      while(number % i == 0) {
        coef++;
        number /= i;
      }
      sol.push_back({i, coef});
    }
  }
  if(1 < number)
    sol.push_back({number, 1});
  return sol;
}

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

int inverse(int number) {
  int x = 0, y = 0;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x <= 0)
    x += modulo;
  return x;
}

int getcoef(int number, int p) {
  int coef = 0;
  while(number % p == 0) {
    number /= p;
    coef++;
  }
  return coef;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n >> modulo;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int q;
  std::cin >> q;
  SegmentTree aint(n), aintrest(n);
  std::vector<std::pair<int,int>> primes = decompose(modulo);
  std::vector<FenwickTree> aib(primes.size());
  aint.build(1, 1, n);
  aintrest.build(1, 1, n);
  
  for(int j = 0; j < primes.size(); j++)
    aib[j] = FenwickTree(n);

  for(int i = 1; i <= n; i++) {
    int val = v[i];
    for(int j = 0; j < primes.size(); j++) {
      int p = primes[j].first;
      int coef = getcoef(v[i], p);
      aib[j].update(i, coef);
      aib[j].update(i + 1, -coef);
      for(int h = 1; h <= coef; h++)
        val /= p;
    }
    aintrest.setvalue(1, 1, n, i, val);
  }

  for(int i = 1;i <= q; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int l, r, val;
      std::cin >> l >> r >> val;
      aint.update(1, 1, n, l, r, val);
      for(int j = 0; j < primes.size(); j++) {
        int p = primes[j].first;
        int coef = getcoef(val, p);
        for(int h = 1; h <= coef; h++)
          val /= p;
        aib[j].update(l, coef);
        aib[j].update(r + 1,-coef);
      }
      aintrest.update(1, 1, n, l, r, val);
    } else if(op == 2) {
      int pos, val;
      std::cin >> pos >> val;
      
      for(int j = 0; j < primes.size(); j++) {
        int p = primes[j].first;
        int coef = getcoef(val, p);
        for(int h = 1; h <= coef; h++)
          val /= p;
        aib[j].update(pos, -coef);
        aib[j].update(pos + 1, coef);
      }

      aintrest.update(1, 1, n, pos, pos, inverse(val));
      int curr = aintrest.query(1, 1, n, pos, pos);
      for(int j = 0; j < primes.size(); j++) {
        int p = primes[j].first;
        curr = 1LL * curr * lgpow(p, aib[j].query(pos)) % modulo;
      }
      aint.setvalue(1, 1, n, pos, curr);
    } else {
      int x, y;
      std::cin >> x >> y;
      std::cout << aint.query(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}