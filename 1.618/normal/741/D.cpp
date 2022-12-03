/*
start thinking:
BULB:
result of thinking:

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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 500005
int n, msk[maxn], dfn[maxn], ind, siz[maxn], son[maxn], ori[maxn], dep[maxn];
vector<int> chi[maxn];
int maxdep[(1 << 22) + 5], ans[maxn];

void dfs1(int u, int f) {
  dep[u] = dep[f] + 1;
  dfn[u] = ++ind;
  ori[ind] = u;
  siz[u] = 1;
  for (auto v : chi[u]) {
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]])
      son[u] = v;
  }
}

void dfs2(int u, bool keep) {
  for (auto v : chi[u]) {
    if (v != son[u])
      dfs2(v, false);
  }
  if (son[u])
    dfs2(son[u], true);
  for (auto v : chi[u]) {
    chmax(ans[u], ans[v]);
    if (v != son[u]) {
      for (int i = dfn[v]; i < dfn[v] + siz[v]; i++) {
        chmax(ans[u], maxdep[msk[ori[i]]] + dep[ori[i]] - 2 * dep[u]);
        for (int j = 0; j < 22; j++)
          chmax(ans[u], maxdep[msk[ori[i]] ^ (1 << j)] + dep[ori[i]] - 2 * dep[u]);
      }
      for (int i = dfn[v]; i < dfn[v] + siz[v]; i++)
        chmax(maxdep[msk[ori[i]]], dep[ori[i]]);
    }
  }
  chmax(ans[u], maxdep[msk[u]] - dep[u]);
  for (int j = 0; j < 22; j++)
    chmax(ans[u], maxdep[msk[u] ^ (1 << j)] - dep[u]);
  chmax(maxdep[msk[u]], dep[u]);
  if (!keep) {
    for (int i = dfn[u]; i < dfn[u] + siz[u]; i++)
      maxdep[msk[ori[i]]] = 0xc0c0c0c0;
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    char s[5]; int f;
    scanf("%d%s", &f, s);
    chi[f].push_back(i);
    msk[i] = msk[f] ^ (1 << (s[0] - 'a'));
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << msk[i] << " ";
  // }
  // cout << endl;
  // system("pause");

  dfs1(1, 0);
  memset(maxdep, 0xc0, sizeof(maxdep));
  dfs2(1, true);
  for (int i = 1; i <= n; i++) {
    printf("%d%c", ans[i], " \n"[i == n]);
  }
  return 0;
}