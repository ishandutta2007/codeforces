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

const int maxn = 2010;
int n;

vector <int> E[maxn];

bool vis[maxn];
int root, minsz, sumsz, sz[maxn];

void dfs1(int u, int f) {
  sz[u] = 1;
  int val = 0;
  for (int v : E[u]) {
    if (!vis[v] && v != f) {
      dfs1(v, u);
      sz[u] += sz[v], chkmax(val, sz[v]);
    }
  }
  chkmax(val, sumsz - sz[u]);
  if (minsz > val) {
    root = u, minsz = val;
  }
}

void dfs2(int u, int f) {
  vis[u] = 1;
  for (int v : E[u]) if (!vis[v] && v != f) {
    dfs2(v, u);
  }
}

void divide(int u) {
  minsz = n + 1;
  dfs1(u, 0);
  u = root;
  int cnt = 0, pos;
  for (int v : E[u]) if (!vis[v]) {
    cnt++, pos = v;
  }
  if (!cnt) {
    cout << "! " << u << endl;
    fflush(stdout);
    exit(0);
  }
  if (cnt == 1) {
    cout << "? " << u << ' ' << pos << endl;
    fflush(stdout);
    int anc;
    cin >> anc;
    fflush(stdout);
    if (anc == u) {
      dfs2(pos, u), sumsz -= sz[pos], divide(u);
    } else {
      dfs2(u, pos), sumsz = sz[pos], divide(pos);
    }
    return;
  }
  vector <int> vec;
  for (int v : E[u]) if (!vis[v]) {
    vec.push_back(v);
  }
  int v1 = vec[rand() % ((int) vec.size())], v2;
  do {
    v2 = vec[rand() % ((int) vec.size())];
  } while (v1 == v2);
  cout << "? " << v1 << ' ' << v2 << endl;
  fflush(stdout);
  int anc;
  cin >> anc;
  if (anc == u) {
    dfs2(v1, u), dfs2(v2, u), sumsz -= sz[v1] + sz[v2], divide(u);
  } else if (anc == v1 || anc == v2) {
    if (anc == v2) swap(v1, v2);
    dfs2(u, v1), sumsz = sz[v1], divide(v1);
  }
}

int main() {
  srand(Rnd());
  n = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    E[u].push_back(v), E[v].push_back(u);
  }
  sumsz = n, divide(1);
  return 0;
}