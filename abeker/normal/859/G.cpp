#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e5 + 5;
const int ITER = 1e3;

int N;
char s[MAXN];

inline int add(int x, int y, int mod) {
  x += y;
  if (x >= mod)
    return x - mod;
  return x;
}

inline int mul(int x, int y, int mod) {
  return (long long)x * y % mod;
}

int pot(int x, int y, int mod) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x, mod);
    x = mul(x, x, mod);
  }
  return res;
}

vector <int> factors(int x) {
  vector <int> res;
  for (int i = 2; i * i <= x; i++)
    if (!(x % i)) {
      res.push_back(i);
      while (!(x % i))
        x /= i;
    }
  if (x > 1)
    res.push_back(x);
  return res;
}

bool is_prime(int x) {
  vector <int> tmp = factors(x);
  return tmp.size() == 1 && x == tmp[0];
}

int get_root(int p) {
  vector <int> tmp = factors(p - 1);
  while (1) {
    int cand = uniform_int_distribution <int> (1, p - 1)(rng);
    auto check = [&]() {
      for (auto it : tmp)
        if (pot(cand, (p - 1) / it, p) == 1)
          return false;
      return true;
    };
    if (check())
      return cand;
  }
}

int eval(int x, int p) {
  int res = 0;
  for (int i = 0; i < N; i++)
    res = add(mul(res, x, p), s[i] - '0', p);
  return res;
}

int main() {
  scanf("%d%s", &N, s);
  for (int i = 0; i < ITER; i++) {
    int tmp = i * N + 1;
    if (is_prime(tmp) && eval(pot(get_root(tmp), i, tmp), tmp)) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}