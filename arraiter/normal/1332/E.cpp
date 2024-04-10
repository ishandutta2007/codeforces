#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int P = 998244353;
int n, m, K;

int qp(int a, ll k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

int main() {
  int L, R;
  cin>> n>>m>>L>>R;
  K = R - L;
  if (1ll * n * m % 2 == 1) {
    cout << qp(K + 1, 1ll * n * m);
    return 0;
  }
  if (K == 0) {
    cout << 1; return 0;
  }
  cout << 1ll * (P + 1) / 2 * ((K % 2 == 0) ? (qp(K + 1, 1ll * n * m) + 1) % P : qp(K + 1, 1ll * n * m)) % P;
  return 0;
}