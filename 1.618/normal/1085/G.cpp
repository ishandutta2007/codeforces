/*
start thinking:
BULB:
result of thinking:

BM := Beautiful Matrix.
=BMBM.
BMlcp, n^2, .
D(n) := n-.
f(i, j): 1~(i+j)p_1...p_{i+j}.
         - 1 <= k <= i, p_k != k.
(fi + j <= n)
|(a[r][1...(c - 1)]x)  a[r - 1][1...c]|:
(i, j)id[1]~id[a[i][j]] - id[a[i][1~j]]<=j.
BIT.

start coding:
AC:
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

#define maxn 2005
const int mod = 998244353;
int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}

int n, a[maxn][maxn], f[maxn][maxn], bit1[maxn], bit2[maxn], id[maxn];

void add(int* bit, int pos, int x) {
  if (!pos)
    return;
  for (int i = pos; i <= n; i += i & -i) {
    bit[i] += x;
  }
}
int qsum(int* bit, int pos) {
  int res = 0;
  for (int i = pos; i; i -= i & -i)
    res += bit[i];
  return res;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);
  }
  f[0][0] = 1, f[1][0] = 0;
  for (int i = 2; i <= n; i++)
    f[i][0] = (i - 1) * ll(f[i - 1][0] + f[i - 2][0]) % mod;
  for (int i = 1; i <= n; i++)
    f[0][i] = (ll)f[0][i - 1] * i % mod;
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      f[i][j] = (f[i + 1][j - 1] + f[i][j - 1]) % mod;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    static int coe[maxn], lis[maxn];
    memset(bit1, 0, sizeof(bit1));
    memset(coe, 0, sizeof(coe));
    for (int j = 1; j <= n; j++)
      lis[j] = j;
    sort(lis + 1, lis + n + 1, [&](int x, int y) { return a[i][x] < a[i][y]; });
    for (int j = 1; j <= n; j++) {
      add(bit1, id[j], 1);
      coe[lis[j]] = qsum(bit1, lis[j]);
    }

    memset(bit1, 0, sizeof(bit1));
    vector<int> d[maxn];
    for (int j = 1; j <= n; j++) {
      d[max(j, id[a[i][j]])].push_back(a[i][j]);
    }
    for (int j = 1; j <= n; j++) {
      for (auto k : d[j])
        add(bit1, k, 1);
      coe[j] -= qsum(bit1, a[i][j]);
    }

    memset(bit2, 0, sizeof(bit2));
    memset(bit1, 0, sizeof(bit1));
    for (int j = 1; j <= n; j++) {
      add(bit2, a[i][j], 1);
      auto foo = j - qsum(bit1, j), coe1 = coe[j], 
           coe2 = a[i][j] - qsum(bit2, a[i][j]) - coe1;
      if (i > 1 && a[i - 1][j] < a[i][j]
          && qsum(bit2, a[i - 1][j]) == qsum(bit2, a[i - 1][j] - 1))
        coe1--;
      if (i == 1) {
        coe2 += coe1, coe1 = 0;
        ans = (ans + (ll)f[0][n - j] * coe2 % mod * modpow(f[n][0], n - i)) % mod;
      } else {
        if (coe2) {
          ans = (ans + (ll)f[n - j - foo][foo] * coe2 % mod 
                  * modpow(f[n][0], n - i)) % mod;
        }
        if (coe1) {
          ans = (ans + (ll)f[n - j - foo + 1][foo - 1] * coe1 % mod 
                  * modpow(f[n][0], n - i)) % mod;
        }
      }
      add(bit1, id[a[i][j]], 1);
    }
    for (int j = 1; j <= n; j++)
      id[a[i][j]] = j;
  }
  printf("%d\n", (ans + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
/*
5
1 4 2 3 5 
5 1 3 4 2
3 2 4 1 5
1 4 5 3 2
5 2 3 4 1
*/