#include <bits/stdc++.h>
using namespace std;

bool vis[205];
int n, m, k, st[10], id[205][205], mp[205], val[205], ans[205], Q[1 << 14 | 5], dp[205][1 << 7 | 5];

struct node {
  int u, S;
} pre[205][1 << 7 | 5];

bool chkmin(int &x, int y) {
  return x > y ? x = y, 1 : 0;
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void spfa(int S, int l, int r) {
  while (l <= r) {
    int u = Q[l++];
    int x = u / m, y = u % m;
    vis[u] = 0;
    for (int i = 0; i < 4; i++) {
      int tx = x + dx[i], ty = y + dy[i];
      if (tx < 0 || ty < 0 || tx == n || ty == m) continue;
      int v = id[tx][ty], T = val[v] ? S : S | 1 << mp[v];
      if (chkmin(dp[v][T], dp[u][S] + val[v])) {
        if (S == T && !vis[v]) {
          Q[++r] = v, vis[v] = 1;
        }
        pre[v][T] = node{u, S};
      }
    }
  }
}

void print(int u, int S) {
  node tmp = pre[u][S];
  if (!tmp.u && !tmp.S) return;
  ans[tmp.u] = 1;
  if (u == tmp.u) {
    print(u, S ^ tmp.S);
  }
  print(tmp.u, tmp.S);
}

int main() {
  int tpas = 0;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int &x = id[i][j];
      x = i * m + j;
      scanf("%d", &val[x]);
    }
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    int t = id[x - 1][y - 1];
    tpas += val[t], val[t] = 0, mp[t] = i, st[i] = t;
  }
  if (k == n * m) {
    printf("%d\n", tpas);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++){
        putchar('X');
      }
      puts("");
    }
    return 0;
  }
  int all = (1 << k) - 1;
  memset(dp, 0x3f, sizeof dp);
  for (int i = 0; i < k; i++) {
    dp[st[i]][1 << i] = 0;
  }
  for (int S = 1; S <= all; S++) {
    int l = 1, r = 0;
    for (int i = 0; i < n * m; i++) {
      for (int sub = S; sub; sub = (sub - 1) & S) {
        if (chkmin(dp[i][S], dp[i][sub] + dp[i][S ^ sub] - val[i])) {
          pre[i][S] = node{i, sub};
        }
      }
      if (dp[i][S] < 1e9) Q[++r] = i, vis[i] = 1;
    }
    spfa(S, l, r);
  }
  int res = 1 << 30, rt = -1;
  for (int i = 0; i < id[n - 1][m - 1]; i++) {
    if (chkmin(res, dp[i][all])) rt = i;
  }
  print(rt, all);
  printf("%d\n", res + tpas);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = id[i][j];
      if (!val[x]) {
        putchar('X');
      } else {
        putchar(ans[x] ? 'X' : '.');
      }
    }
    putchar(10);
  }
  return 0;
}