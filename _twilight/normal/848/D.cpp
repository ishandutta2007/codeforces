#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

void exgcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1, y = 0;
  } else {
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
}

int inv(int a, int n) {
  int x, y;
  exgcd(a, n, x, y);
  return (x < 0) ? (x + n) : (x);
}

const int Mod = 1e9 + 7;

template <const int Mod = :: Mod>
class Z {
  public:
    int v;

    Z() : v(0) {	}
    Z(int x) : v(x){	}
    Z(ll x) : v(x % Mod) {	}

    Z operator + (Z b) {
      int x;
      return Z(((x = v + b.v) >= Mod) ? (x - Mod) : (x));
    }
    Z operator - (Z b) {
      int x;
      return Z(((x = v - b.v) < 0) ? (x + Mod) : (x));
    }
    Z operator * (Z b) {
      return Z(v * 1ll * b.v);
    }
    Z operator ~() {
      return inv(v, Mod);
    }
    Z operator - () {
      return Z(0) - *this;
    }
    Z& operator += (Z b) {
      return *this = *this + b;
    }
    Z& operator -= (Z b) {
      return *this = *this - b;
    }
    Z& operator *= (Z b) {
      return *this = *this * b;
    }
};

Z<> qpow(Z<> a, int p) {
  Z<> rt = Z<>(1), pa = a;
  for ( ; p; p >>= 1, pa = pa * pa) {
    if (p & 1) {
      rt = rt * pa;
    }
  }
  return rt;
}

typedef Z<> Zi;

const int N = 55;

int n, m;
Zi fac[N], _fac[N];
Zi f[N][N], g[N][N], P[N];

inline void init_fac() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i; 
  }
  _fac[n] = ~fac[n];
  for (int i = n; i; i--) {
    _fac[i - 1] = _fac[i] * i;
  }
}

int main() {
  scanf("%d%d", &n, &m);	
  init_fac();
  f[0][1] = 1;
  for (int sz = 1; sz <= n; sz++) {
    for (int cut = 1; cut <= sz; cut++) {
      for (int a = 0, c; a < sz; a++) {
        c = sz - a - 1;
        for (int i = cut; i <= sz; i++) {
          g[sz][cut] += f[a][cut] * f[c][i] + f[c][cut] * f[a][i + 1]; 
        }
      }
      P[0] = 1;
      for (int x = 1; x * sz <= n; x++) {
        P[x] = P[x - 1] * (g[sz][cut] + x - 1);
      }
      for (int x = 1; x * sz <= n; x++) {
        P[x] *= _fac[x];
      }
      for (int i = n; i >= sz; i--) {
        for (int j = n + 1; j > cut; j--) {
          for (int x = 1; x * sz <= i && x * cut < j; x++) {
            f[i][j] += f[i - x * sz][j - x * cut] * P[x];
          }
        } 
      }
    }
  }
  printf("%d\n", f[n][m].v);
  return 0;
}