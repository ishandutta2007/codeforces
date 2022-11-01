#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 505;
const int MOD = 1e9 + 7;
 
struct polynomial {
  int deg;
  long long coeff[N];
 
  polynomial () {
    deg = 0;
    memset(coeff, 0, sizeof coeff);
  }

  long long at (long long x) {
    long long ret = 0;
    for (int i = deg; i >= 0; --i) {
      ret *= x, ret += coeff[i], ret %= MOD;
    }
    return ret;
  }
};

int f, b, m, _b[N];
polynomial u, d, x, y;
long long n, _f[N];

long long inverse (long long a) {
  long long e = MOD - 2, r = 1;
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD, e >>= 1;
  }
  return r;
}

polynomial add (polynomial f, polynomial g) {
  polynomial h;
  h.deg = max(f.deg, g.deg);
  for (int i = 0; i <= h.deg; ++i) {
    h.coeff[i] = (f.coeff[i] + g.coeff[i]) % MOD;
  }
  while (h.deg > 0 and h.coeff[h.deg] == 0) {
    --h.deg;
  }
  return h;
}

polynomial product (polynomial f, polynomial g) {
  polynomial h;
  h.deg = f.deg + g.deg;
 
  for (int i = 0; i <= f.deg; ++i)
    for (int j = 0; j <= g.deg; ++j)
      h.coeff[i + j] += f.coeff[i] * g.coeff[j], h.coeff[i + j] %= MOD;
 
  return h;
}
 
// Assuming deg f >= deg g
polynomial quotient (polynomial f, polynomial g) {
  polynomial q;
  q.deg = f.deg - g.deg;
 
  for (int i = q.deg; i >= 0; --i) {
    q.coeff[i] = (f.coeff[g.deg + i] * inverse(g.coeff[g.deg])) % MOD;
    for (int j = g.deg; j >= 0; --j) 
      f.coeff[i + j] -= q.coeff[i] * g.coeff[j], f.coeff[i + j] %= MOD;   
  }
 
  return q;
}
 
polynomial remainder (polynomial f, polynomial g) {
  if (f.deg < g.deg) return f;
 
  for (int i = f.deg - g.deg; i >= 0; --i) {
    long long c = (f.coeff[g.deg + i] * inverse(g.coeff[g.deg])) % MOD;
    for (int j = g.deg; j >= 0; --j) 
      f.coeff[i + j] -= c * g.coeff[j], f.coeff[i + j] %= MOD;   
  }
 
  f.deg = g.deg - 1;
  while (f.coeff[f.deg] == 0) --f.deg;
  f.deg = max(f.deg, 0);
  return f;
}

polynomial bigMod (polynomial g, long long e, polynomial mod) {
  if (e == -1) e = MOD - 2;
  polynomial r;
  r.coeff[0] = 1;
  while (e) {
    if (e & 1) r = remainder(product(r, g), mod);
    g = remainder(product(g, g), mod), e >>= 1;
  }
  return r;
}

void print (polynomial &f) {
  for (int i = f.deg; i >= 0; --i) {
    long long cur = f.coeff[i];
    if (cur == 0) continue;
    if (i < f.deg) {
      if (f.coeff[i] > 0) {
        printf("+ ");
      } else {
        printf("- ");
      }
    }
    cur = abs(cur);
    if (cur != 1) {
      printf("%lld ", cur);
    }
    if (i == 0) {
      if (cur == 1) {
        printf("%lld ", cur);
      }
    } else {
      printf("x^%d ", i);
    }
  }
  puts("");
}

int main() {
  x.deg = 1, x.coeff[1] = 1;
  scanf("%d %d %lld", &f, &b, &n);
  for (int i = 0; i < f; ++i) {
    scanf("%lld", _f + i);
  }
  for (int i = 0; i < b; ++i) {
    scanf("%d", _b + i);
    m = max(m, _b[i]);
  }
  d.deg = m;
  for (int i = 0; i < b; ++i) {
    d.coeff[m - _b[i]] -= 1;
  }
  y.deg = m, y.coeff[m] = 1;
  d = add(d, y);
  // print(d);
  for (int i = 0; i < f; ++i) {
    u = add(u, bigMod(x, _f[i], d));
  }
  u = bigMod(u, n, d);
  u = remainder(product(u, y), d);
  for (int i = 0; i <= u.deg; ++i) {
    u.coeff[i] = -u.coeff[i];
  }
  long long _u = u.at(0), _d = d.at(0);
  long long ans = (_u * inverse(_d)) % MOD;
  ans += MOD, ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}