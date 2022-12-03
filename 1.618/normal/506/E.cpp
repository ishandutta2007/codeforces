/*
start thinking:
BULB:
result of thinking: Lost.

t(i.e. s)
t.front()=s.front()t.front(), t.back().
f(n, l, r): ne.g. 32), s[l, r], .
n1e9.
F_{l, r}Polynomial, .
(l^4logn), gg.
O(l^6logn), .
.

start coding:
AC:

: dp: 24()
      25(). =STm. 
      1, 2, ..., mS-T
      . O(l)
      ag(a)TS-Tm.
      ![](https://codeforces.com/predownloaded/1a/46/1a46a6e5a205f97d99f47d51742923169cd65aa4.png)
      m. O(l^3logn).
      [x^m]1/((1-24x)^n24(1-25x)^n25(1-26x))
      ()O(l^2logn).
      O(l)O(l^3logn).
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxm 205
#define maxV 405
const int mod = 10007;

// f(l, r, n24)
int n, l, m, f[maxm][maxm][maxm];
char s[maxm];

int S, A[maxV][maxV];

// a *= b
void matmul(int a[][maxV], int b[][maxV]) {
  static int foo[maxV][maxV];
  memset(foo, 0, sizeof(foo));
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < S; j++) {
      for (int k = i; k <= j; k++) {
        (foo[i][j] += a[i][k] * b[k][j]) %= mod;
      }
    }
  }
  for (int i = 0; i < S; i++)
    memcpy(a[i], foo[i], sizeof(foo[i]));
}

// a := a^n
void matpow(int a[][maxV], ll n) {
  int B[maxV][maxV];
  memset(B, 0, sizeof(B));
  for (int i = 0; i < S; i++)
    B[i][i] = 1;
  while (n) {
    if (n & 1) matmul(B, a);
    matmul(a, a);
    n >>= 1;
  }
  for (int i = 0; i < S; i++)
    memcpy(a[i], B[i], sizeof(B[i]));
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%s%d", s + 1, &n);
  l = strlen(s + 1);
  n += l;
  m = (n + 1) / 2;

  for (int w = 1; w <= l; w++) {
    for (int i = 1; i + w - 1 <= l; i++) {
      int j = i + w - 1;
      for (int n24 = 0; n24 < l; n24++) {
        if (i == j) {
          if (!n24)
            f[i][j][n24] = 1;
        } else {
          if (s[i] == s[j]) {
            if (i + 1 == j) {
              if (!n24)
                f[i][j][n24] = 1;
            } else {
              f[i][j][n24] = f[i + 1][j - 1][n24];
            }
          } else {
            if (n24)
              f[i][j][n24] = (f[i][j - 1][n24 - 1] + f[i + 1][j][n24 - 1]) % mod;
          }
        }
      }
    }
  }

  // for (int i = 0; i < l; i++)
  //   cout << f[1][l][i] << " ";
  // cout << endl;
  // system("pause");

  int N24 = l - 1, N25 = (l + 1) / 2, N26 = N25;
  S = N24 + N25 + N26;
  
  for (int j = 0; j < S; j++) {
    if (j < N24) {
      A[j][j] = 24;
      A[j][j + 1] = 1;
    } else if (j < N24 + N25) {
      A[j][j] = 25;
      if (j < N24 + N25 - 1) A[j][j + 1] = 1;
      A[j][j + N25] = 1;
    } else {
      A[j][j] = 26;
    }
  }

  // for (int i = 0; i < S; i++) {
  //   for (int j = 0; j < S; j++)
  //     cout << A[i][j] << " ";
  //   cout << endl;
  // }
  // system("pause");
  
  static int _A[maxV][maxV];
  for (int i = 0; i < S; i++)
    for (int j = 0; j < S; j++)
      _A[i][j] = A[i][j];
  matpow(A, m - 1);

  // for (int i = 0; i < S; i++) {
  //   for (int j = 0; j < S; j++)
  //     cout << A[i][j] << " ";
  //   cout << endl;
  // }
  // system("pause");

  int C[maxV][maxV];
  for (int i = 0; i < S; i++)
    for (int j = 0; j < S; j++)
      C[i][j] = A[i][j];
  matmul(A, _A);

  // for (int i = 0; i < S; i++) {
  //   for (int j = 0; j < S; j++)
  //     cout << A[i][j] << " ";
  //   cout << endl;
  // }
  // system("pause");

  int ans = 0;
  for (int n24 = 0; n24 < l; n24++) {
    int n25 = (l - n24 + 1) / 2;
    bool last25_double = (l - n24) % 2 == 0;
    int n26 = m - n24 - n25;
    if (n26 < 0)
      continue;
    int ways = f[1][l][n24];
    (ans += ways * A[N24 - n24][N24 + N25 + n25 - 1]) %= mod;
    if (n % 2 == 1 && last25_double) {
      (ans -= ways * C[N24 - n24][N24 + n25 - 1]) %= mod;
    }
  }
  printf("%d\n", (ans + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}