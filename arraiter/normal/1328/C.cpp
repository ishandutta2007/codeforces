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
const int maxn = 1e5 + 10;
int n, data[maxn], A[maxn], B[maxn];

void solve() {
  n = read();
  rep(i, 1, n) scanf("%1d", data + i);
  A[1] = 1, B[1] = 1;
  bool eq = 1;
  rep(i, 2, n) {
    if (data[i] == 1) {
      if (eq) {
        A[i]=1,B[i]=0;
      }else{
        B[i]=1,A[i]=0;
      }
      eq=0;
    } else {
      if (eq)A[i]=B[i]=data[i]/2;
      else B[i]=data[i],A[i]=0;
    }
  }
  rep(i, 1, n)putchar(A[i]|48);
  puts("");
  rep(i,1,n)putchar(B[i]|48);
  puts("");
}

int main() {
  int T = read();
  while(T--)solve();
  return 0;
}