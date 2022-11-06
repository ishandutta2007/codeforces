#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 998244353;
const int N = 201000;
inline int qpow(int x, int y) {
  int res(1);
  while (y) {
    if (y & 1) res = 1ll * res * x % P;
    x = 1ll * x * x % P;
    y >>= 1;
  }
  return res;
}

int r[N];

void ntt(int *x, int lim, int opt) {
 int i, j, k, m, gn, g, tmp;
  for (i = 0; i < lim; ++i)
    if (r[i] < i) swap(x[i], x[r[i]]);
  for (m = 2; m <= lim; m <<= 1) {
    k = m >> 1;
    gn = qpow(3, (P - 1) / m);
    for (i = 0; i < lim; i += m) {
      g = 1;
      for (j = 0; j < k; ++j, g = 1ll * g * gn % P) {
        tmp = 1ll * x[i + j + k] * g % P;
        x[i + j + k] = (x[i + j] - tmp + P) % P;
        x[i + j] = (x[i + j] + tmp) % P;
      }
    }
  }
  if (opt == -1) {
    reverse(x + 1, x + lim);
    int inv = qpow(lim, P - 2);
    for (i = 0; i < lim; ++i) x[i] = 1ll * x[i] * inv % P;
  }
}
int a[N], b[N], c[N];
void PT(int lim) {
    for (int i = 0; i < lim; ++i) printf("%d ", a[i]); puts("");
    for (int i = 0; i < lim; ++i) printf("%d ", b[i]);puts("");
}

void PT2(int lim) {
    for (int i = 0; i < lim; ++i) printf("%d ", c[i]);puts("");
    puts("");
}
void doit(int lim) {
    //PT(lim);
    int i;
    for (i = 0; i < lim; ++i) r[i] = (i & 1) * (lim >> 1) + (r[i >> 1] >> 1);
    ntt(a, lim, 1);
    ntt(b, lim, 1);
    for (i = 0; i < lim; ++i) c[i] = 1ll * a[i] * b[i] % P;
    ntt(c, lim, -1);
    //PT2(lim);
}

const int V = 200100;
const int NN = 5100;
int dp[NN][NN];
int fac[V], rev[V], C[V], n,A, B;
int main() {
    fac[0] = 1;
    for (int i = 1; i <= V - 10; ++i) fac[i] = (LL) fac[i - 1] * qpow(i, P - 2);
    for (int i = 1; i <= V - 10; ++i) rev[i] = qpow(i, P - 2);
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int col = 1;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &A, &B);
            C[0] = 1;
            for (int j = 1; j <= A + B; ++j) C[j] = (LL) C[j - 1] * (A + B - j + 1) % P * rev[j] % P;
            //for (int j = 1; j <= A + B; ++j) printf("%d ", C[j]); puts("");
            int lim = 1;
            while (lim < col * 2) lim *= 2;
            col += A - B;
            while (lim < col * 2) lim *= 2;
            for (int j = 0; j < lim; ++j) a[j] = 0;
            for (int j = 0; j < lim; ++j) b[j] = 0;
            for (int j = 0; j < lim; ++j) if(j < NN) a[j] = dp[i][j];
            for (int j = -B; j <= A; ++j) if (j + lim / 2 < lim && j + lim / 2 >= 0) b[j + lim / 2] = C[B + j];
            doit(lim);
            for (int j = 0; j < col; ++j) dp[i + 1][j] = c[j + lim / 2];
        }
        int ans = 0;
        for (int i = 0; i < col; ++i) ans = (ans + dp[n][i]) % P;
        printf("%d\n", ans);
    }
    return 0;
}

/*
2
4 2
2 3

3
4 1
2 3
3 1

8
328 323
867 868
715 718
721 722
439 435
868 870
834 834
797 796
*/