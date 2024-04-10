#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 998244353;
const int MAXG = 1 << 9;

class Mint {
  int x;
public:
  Mint(int x) : x(x) {}
  Mint() : x(0) {}
  Mint operator +(const Mint &rhs) const {
    int res = x + rhs.x;
    if (res >= MOD)
      return res - MOD;
    if (res < 0)
      return res + MOD;
    return res;
  }
  Mint operator -(const Mint &rhs) const {
    return *this + Mint(-rhs.x);
  }
  Mint operator *(const Mint &rhs) const {
    return (long long)x * rhs.x % MOD;
  }
  void operator +=(const Mint &rhs) {
    *this = *this + rhs;
  }
  void operator -=(const Mint &rhs) {
    *this = *this - rhs;
  }
  void operator *=(const Mint &rhs) {
    *this = *this * rhs;
  }
  Mint operator /(Mint rhs) const {
    Mint res = *this;
    for (int ex = MOD - 2; ex; ex /= 2) {
      if (ex % 2)
        res *= rhs;
      rhs *= rhs;
    }
    return res;
  }
  int get() const {
    return x;
  }
};

class Matrix {
  int n;
  vector <vector <Mint>> a;
public:
  Matrix(Mint _a[MAXG][MAXG], int st, int _n) {
    n = _n;
    a = vector <vector <Mint>> (n, vector <Mint> (n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        a[i][j] = _a[st + i][st + j];
  }
  Mint det() {
    Mint res = 1;
    for (int i = 0; i < n; i++) {
      for (int k = i; k < n; k++)
        if (a[k][i].get()) {
          swap(a[i], a[k]);
          if (k > i)
            res *= MOD - 1;
          break;
        }
      Mint tmp = a[i][i];
      assert(tmp.get());
      res *= tmp;
      tmp = Mint(1) / tmp;
      for (int j = 0; j < n; j++)
        a[i][j] *= tmp;
      for (int k = i + 1; k < n; k++) 
        for (int j = n - 1; j >= i; j--)
          a[k][j] -= a[k][i] * a[i][j];
    }
    return res;
  }
};

int N, M;
vector <int> adj[MAXN];
Mint mat[MAXG][MAXG];
int dp[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
  }
}

int grundy(int x) {
  if (dp[x] != -1)
    return dp[x];
  int sz = adj[x].size();
  vector <bool> used(sz + 1);
  for (auto it : adj[x]) {
    int tmp = grundy(it);
    if (tmp <= sz)
      used[tmp] = true;
  }
  for (dp[x] = 0; used[dp[x]]; dp[x]++);
  return dp[x];
}

int solve() {
  memset(dp, -1, sizeof dp);
  vector <int> freq(MAXG);
  for (int i = 1; i <= N; i++)
    freq[grundy(i)]++;
  Mint inv = Mint(1) / Mint(N + 1);
  for (int i = 0; i < MAXG; i++)
    for (int j = 0; j < MAXG; j++) 
      mat[i][j] = Mint(i == j) - inv * Mint(freq[i ^ j]);
  return (Mint(1) - inv * Matrix(mat, 1, MAXG - 1).det() / Matrix(mat, 0, MAXG).det()).get();
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}