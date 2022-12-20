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

const int maxn = 5010;
vector <int> res;
int n, m, a[maxn];

int main() {
  n = read(), m = read();
  int c = 0, r = 0;
  rep(i, 1, n) {
    if (m <= (i - 1) / 2 + c) {
      int j = i;
      while (1) {
        if ((i + i - j - 1) / 2 + c == m) {
          for (int x : res) printf("%d ", x), ++r;
          printf("%d ", j), ++r;
          int t = 5e8;
          rep(T, r + 1, n) {
            printf("%d ", t), t += 10000;
          }
          return 0;
        }
        ++j;
      }
    } else {
      res.push_back(i), c += (i - 1) / 2;
    }
  }
  puts("-1");
  return 0;
}