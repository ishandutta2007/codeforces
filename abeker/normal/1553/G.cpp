#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1.5e5 + 5;
const int MAXV = 2e6 + 5;

int N, Q;
int a[MAXN];
set <pii> cands;
vector <int> factors[MAXV];
int dad[MAXV], rnk[MAXV];
int p[MAXV];

void load() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

int query(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return 0;
  if (x > y)
    swap(x, y);
  if (cands.count({x, y}))
    return 1;
  return 2;
}

void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (rnk[x] > rnk[y])
    swap(x, y);
  dad[x] = y;
  rnk[y] += rnk[x] == rnk[y];
}

void solve() {
  iota(dad, dad + MAXV, 0);
  for (int i = 2; i < MAXV; i++)
    if (!p[i])
      for (int j = i; j < MAXV; j += i)
        if (!p[j])
          p[j] = i;
  for (int i = 2; i < MAXV; i++)
    for (int x = i; x > 1; x /= p[x])
      if (factors[i].empty() || p[x] != factors[i].back())
        factors[i].push_back(p[x]);
  for (int i = 1; i <= N; i++)
    for (auto it : factors[a[i]])
      join(i, it + N);
  for (int i = 1; i <= N; i++) {
    set <int> tmp = {find(i)};
    for (auto it : factors[a[i] + 1])
      tmp.insert(find(it + N));
    for (auto it1 : tmp)
      for (auto it2 : tmp)
        if (it1 < it2)
          cands.insert({it1, it2});
  }
  while (Q--) {
    int s, t;
    scanf("%d%d", &s, &t);
    printf("%d\n", query(s, t));
  }
}

int main() {
  load();
  solve();
  return 0;
}