/*
start thinking:
BULB:
result of thinking: Pure.

<=2.

start coding:
AC:
*/
#include <bits/stdc++.h>
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

#define maxq 300005
#define maxn 150005
int n, id[1000005], q, s[maxq], t[maxq], rep[1000005], ans[maxq];
bool notp[1000005];
vector<int> one[maxn], fac[1000005];

namespace Dsu {
  int par[maxn];

  void init(int n) {
    for (int i = 1; i <= n; i++)
      par[i] = i;
  }

  int fin(int u) { return par[u] == u ? u : (par[u] = fin(par[u])); }

  void uni(int u, int v) {
    u = fin(u), v = fin(v);
    if (u == v)
      return;
    par[u] = v;
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    id[a] = i;
  }
  for (int i = 1; i <= q; i++)
    scanf("%d%d", s + i, t + i);
  notp[1] = true;
  Dsu::init(n);
  for (int i = 2; i <= 1000000; i++) {
    if (notp[i])
      continue;
    int lst = 0;
    for (int j = i; j <= 1000000; j += i) {
      if (j > i)
        notp[j] = true;
      if (id[j]) {
        if (lst)
          Dsu::uni(lst, id[j]);
        rep[i] = lst = id[j];
      }
    }
  }
  fill(ans + 1, ans + q + 1, 2);
  for (int i = 1; i <= q; i++) {
    s[i] = Dsu::fin(s[i]), t[i] = Dsu::fin(t[i]);
    if (s[i] == t[i])
      ans[i] = 0;
  }
  for (int i = 2; i <= 1000000; i++) {
    if (id[i])
      fac[i + 1].push_back(Dsu::fin(id[i]));
  }
  for (int i = 2; i <= 1000000; i++) {
    if (notp[i] || !rep[i])
      continue;
    for (int j = i; j <= 1000001; j += i) {
      if (id[j - 1])
        fac[j].push_back(Dsu::fin(rep[i]));
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (id[i]) {
      for (auto j : fac[i + 1]) {
        for (auto k : fac[i + 1]) {
          one[j].push_back(k);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
    sort(one[i].begin(), one[i].end());
  for (int i = 1; i <= q; i++) {
    if (binary_search(one[s[i]].begin(), one[s[i]].end(), t[i]))
      chmin(ans[i], 1);
  }
  for (int i = 1; i <= q; i++)
    printf("%d\n", ans[i]);
  return 0;
}
/*
5 1
3 8 7 6 25
1 5
*/