#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

class Fenwick {
  int n;
  vector <int> fen;
public:
  Fenwick(int n) : n(n) {
    fen.resize(n + 1);
  }
  void update(int x, int val) {
    for (x++; x <= n; x += x & -x)
      fen[x] = add(fen[x], val);
  }
  int get(int x) {
    int res = 0;
    for (x++; x; x -= x & -x)
      res = add(res, fen[x]);
    return res;
  }
  int query(int x, int y) {
    return add(get(y), -get(x - 1));
  }
};

int N;
int a[MAXN];
int lft[MAXN], rig[MAXN];
int sub[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

int solve() {
  vector <int> comp(a, a + N);
  sort(comp.begin(), comp.end());
  for (int i = 0; i < N; i++)
    a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
  Fenwick L(N), R(N);
  for (int i = 0; i < N; i++) {
    lft[i] = add(L.query(0, a[i] - 1), 1);
    L.update(a[i], lft[i]);
  }
  for (int i = N - 1; i >= 0; i--) {
    rig[i] = add(R.query(a[i] + 1, N - 1), 1);
    R.update(a[i], rig[i]);
  }
  vector <int> pos(N + 1);
  for (int i = 0; i < N; i++)
    pos[a[i]] = max(pos[a[i]], i);
  for (int i = N - 1; i >= 0; i--)
    pos[i] = max(pos[i], pos[i + 1]);
  vector <vector <int>> todo(N);
  for (int i = N - 1; i >= 0; i--)
    if (pos[a[i] + 1] > i)
      todo[pos[a[i] + 1]].push_back(i);
    else
      sub[i] = -1;
  Fenwick S(N);
  for (int i = 0; i < N; i++) {
    S.update(a[i], 1);
    for (auto it : todo[i]) {
      sub[it] = S.query(a[it] + 1, N - 1);
      S.update(a[it], sub[it]);
    }
    S.update(a[i], -1);
    for (auto it : todo[i])
      S.update(a[it], -sub[it]);
  }
  int sol = 0;
  for (int i = 0; i < N; i++)
    if (sub[i] != -1)
      sol = add(sol, mul(lft[i], add(rig[i], -sub[i])));
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}