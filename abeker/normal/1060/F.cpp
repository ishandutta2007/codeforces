#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 55;

struct Table {
  int n;
  vector <vector <ld>> distr;
  Table(int n) : n(n) {
    distr.resize(n + 1);
    for (int i = 0; i <= n; i++)
      distr[i].resize(i + 1);
  }
  vector <ld>& operator [](int x) {
    return distr[x];
  }
};

int N;
vector <int> adj[MAXN];
ld choose[MAXN][MAXN];

Table conv(Table a, Table b) {
  Table c(a.n + b.n);
  for (int i = 0; i <= a.n; i++)
    for (int j = 0; j <= b.n; j++)
      for (int k = 0; k <= i; k++)
        for (int l = 0; l <= j; l++)
          c[i + j][k + l] += a[i][k] * b[j][l];
  return c;
}

Table add_one(Table a) {
  Table b(a.n + 1);
  for (int i = 0; i <= b.n; i++)
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k < b.n; k++) {
        int nxt_i = min(i, k);
        int nxt_j = j - (k < i);
        if (nxt_j >= 0 && nxt_j <= nxt_i)
          b[i][j] += a[nxt_i][nxt_j];
      }
      b[i][j] *= choose[b.n][i] / b.n;
    }
  return b;
}

Table dfs(int x, int p) {
  Table res(0);
  res[0][0] = 1;
  for (auto it : adj[x])
    if (it != p) 
      res = conv(res, add_one(dfs(it, x)));
  for (int i = 0; i <= res.n; i++)
    for (int j = 0; j <= i; j++)
      res[i][j] /= choose[res.n][i];
  return res;
}

ld calc(int x) {
  ld res = 0;
  Table tmp = dfs(x, 0);
  for (int i = 0; i <= tmp.n; i++)
    res += tmp[tmp.n][i] / (1ll << i);
  return res;
}

void load() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void solve() {
  for (int i = 0; i <= N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++)
      choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
  }
  for (int i = 1; i <= N; i++)
    printf("%.10Lf\n", calc(i));
}

int main() {
  load();
  solve();
  return 0;
}