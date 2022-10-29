#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 5e5 + 5;

typedef class dp_t {
  public:
    ll a[2][2];

    dp_t() {
      memset(a, 0, sizeof(a));
    }
    dp_t(ll a00, ll a01, ll a10, ll a11) {
      a[0][0] = a00, a[0][1] = a01;
      a[1][0] = a10, a[1][1] = a11;
    }

    ll* operator [] (int p) {
      return a[p];
    }

    dp_t transform() {
      return dp_t(a[1][0], a[0][0] + a[1][1], a[0][0], a[0][1]);
    }
    dp_t operator + (dp_t b) {
      dp_t rt;
      for (int s0 = 0; s0 < 2; s0++) {
        for (int c0 = 0; c0 < 2; c0++) {
          if (a[s0][c0]) {
            for (int s1 = 0; s0 + s1 < 2; s1++) {
              for (int c1 = 0; c0 + c1 < 2; c1++) {
                rt[s0 + s1][c0 + c1] += a[s0][c0] * b[s1][c1]; 
              }
            }
          }
        }
      }
      return rt;
    }
} dp_t;

int n;
int sz[N];
vector<int> G[N];
dp_t fd[N], fu[N];

int dfs(int p, int fa) {
  sz[p] = 1;
  for (auto e : G[p]) {
    if (e ^ fa) {
      sz[p] += dfs(e, p);
    }
  }
  return sz[p];
}

void dfs1(int p, int fa) {
  fd[p][0][0] = 1;
  for (auto e : G[p]) {
    if (e ^ fa) {
      dfs1(e, p);
      fd[p] = fd[p] + fd[e].transform();
    }
  }
}

void dfs2(int p, int fa) {
  dp_t tmp = fu[p].transform();
  int deg = G[p].size();
  for (int i = 0, e; i < deg; i++) {
    if ((e = G[p][i]) == fa) {
      continue;
    }
    fu[e] = tmp;
    tmp = tmp + fd[e].transform();
  }
  tmp = dp_t();
  tmp[0][0] = 1;
  for (int i = deg - 1, e; ~i; i--) {
    if ((e = G[p][i]) == fa) {
      continue;
    }
    fu[e] = fu[e] + tmp;
    tmp = tmp + fd[e].transform();
  }
  for (auto e : G[p]) {
    if (e ^ fa) {
      dfs2(e, p);
    }
  }
}

int main() {
  scanf("%d", &n);
  if (n & 1) {
    puts("0");
    return 0;
  }
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  fu[1][1][0] = 1;
  dfs(1, 0);
  dfs1(1, 0);
  dfs2(1, 0);
  ll ans = 0;
  for (int u = 2; u <= n; u++) {
    ans += (fd[u][0][0] + fd[u][1][1]) * (fu[u][0][0] + fu[u][1][1]);
    ans += fd[u][1][0] * fu[u][1][0] * sz[u] * (n - sz[u]);
  }
  printf("%lld\n", ans);
  return 0;
}