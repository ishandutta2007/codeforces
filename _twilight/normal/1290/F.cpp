#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
  return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
  return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
  return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
  return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
  return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
  return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
  os << "(" << z.first << ", " << z.second << ')';
  return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
  boolean isfirst = true;
  os << "{";
  for (auto z : a) {
    if (!isfirst) {
      os << ", ";
    }
    os << z;
    isfirst = false;
  }
  os << '}';
  return os;
}

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

const int Mod = 998244353;

template <const int Mod = :: Mod>
class Z {
  public:
    int v;

    Z() : v(0) {	}
    Z(int x) : v(x){	}
    Z(ll x) : v(x % Mod) {	}

    friend Z operator + (const Z& a, const Z& b) {
      int x;
      return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
    }
    friend Z operator - (const Z& a, const Z& b) {
      int x;
      return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
    }
    friend Z operator * (const Z& a, const Z& b) {
      return Z(a.v * 1ll * b.v);
    }
    friend Z operator ~(const Z& a) {
      return inv(a.v, Mod);
    }
    friend Z operator - (const Z& a) {
      return Z(0) - a;
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
    friend boolean operator == (const Z& a, const Z& b) {
      return a.v == b.v;
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

const int N = 5, N4 = N << 2, S = 1 << 5;

int abs(int x) {
  return x < 0 ? -x : x;
}

int n, m;
int x[N], y[N];
int px[S], nx[S], py[S], ny[S];
Zi f[32][N4][N4][N4][N4][2][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int s = 0; s < (1 << n); s++) {
    for (int i = 0; i < n; i++) {
      if ((s >> i) & 1) {
        ((x[i] < 0) ? nx : px)[s] += abs(x[i]);
        ((y[i] < 0) ? ny : py)[s] += abs(y[i]);
      }
    }
  }
  int mpx = max(1, px[(1 << n) - 1]);
  int mnx = max(1, nx[(1 << n) - 1]);
  int mpy = max(1, py[(1 << n) - 1]);
  int mny = max(1, ny[(1 << n) - 1]);
  int bit = 0;
  f[0][0][0][0][0][0][0] = 1;
  for ( ; (1 << bit) <= m; bit++) {
    for (int cpx = 0; cpx < mpx; cpx++) {
      for (int cnx = 0; cnx < mnx; cnx++) {
        for (int cpy = 0; cpy < mpy; cpy++) {
          for (int cny = 0; cny < mny; cny++) {
            for (int olx = 0; olx < 2; olx++) {
              for (int oly = 0; oly < 2; oly++) {
                Zi v = f[bit][cpx][cnx][cpy][cny][olx][oly];
                if (!v.v)
                  continue;
                for (int msk = 0; msk < (1 << n); msk++) {
                  int vpx = cpx + px[msk];
                  int vnx = cnx + nx[msk];
                  int vpy = cpy + py[msk];
                  int vny = cny + ny[msk];
                  if (((vpx ^ vnx) & 1) | ((vpy ^ vny) & 1))
                    continue;
                  int vx = vpx & 1, vy = vpy & 1, bm = (m >> bit) & 1;
                  int nolx = (vx == bm) ? (olx) : (vx > bm);
                  int noly = (vy == bm) ? (oly) : (vy > bm);
                  f[bit + 1][vpx >> 1][vnx >> 1][vpy >> 1][vny >> 1][nolx][noly] += v;
                }
              }
            }
          }
        }
      }
    }
  }
  Zi ans = f[bit][0][0][0][0][0][0] - 1;
  cout << ans.v << '\n';
  return 0;
}