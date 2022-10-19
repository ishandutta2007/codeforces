#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;
const int MAXM = 260;

struct Equation {
  bitset <MAXM> pos[3];
  void setZero() {
    pos[0].set();
  }
  int operator [](int x) const {
    for (int i = 0; i < 3; i++)
      if (pos[i].test(x))
        return i;
    assert(false);
  }
  int get(int x) const {
    return (*this)[x];
  }
  void set(int x, int v) {
    pos[get(x)].set(x, 0);
    pos[v].set(x, 1);
  }
  bool isZero(int m) const {
    for (int i = 0; i < m; i++)
      if (get(i))
        return false;
    return true;
  }
};

inline int add(int x, int y) {
  x += y;
  if (x >= 3)
    return x - 3;
  if (x < 0)
    return x + 3;
  return x;
}

inline void inc(int &x, int y) {
  x = add(x, y);
}

inline int mul(int x, int y) {
  return x * y % 3;
}

Equation operator *(int lambda, const Equation &e) {
  Equation r;
  for (int i = 0; i < 3; i++)
    r.pos[mul(i, lambda)] |= e.pos[i];
  return r;
}

Equation operator -(const Equation &e, const Equation &f) {
  Equation r;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      r.pos[add(i, -j)] |= e.pos[i] & f.pos[j];
  return r;
}

void operator -=(Equation &e, const Equation &f) {
  e = e - f;
}

int N, M;
int clr[MAXM];
int idx[MAXN][MAXN];

void load() {
  scanf("%d%d", &N, &M);
  memset(idx, -1, sizeof idx);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d%d%d", &a, &b, clr + i);
    idx[a][b] = idx[b][a] = i;
  }
}

void solve() {
  vector <Equation> rows;
  for (int i = 0; i < M; i++)
    if (clr[i] != -1) {
      Equation tmp;
      tmp.setZero();
      tmp.set(i, 1);
      tmp.set(M, clr[i] - 1);
      rows.push_back(tmp);
    }
    else
      clr[i] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      for (int k = j + 1; k <= N; k++) {
        vector <int> edges;
        for (auto it : {idx[i][j], idx[j][k], idx[k][i]})
          if (it != -1)
            edges.push_back(it);
        if (edges.size() == 3) {
          Equation tmp;
          tmp.setZero();
          for (auto it : edges)
            tmp.set(it, 1);
          rows.push_back(tmp);
        }
      }
  vector <int> lft;
  for (int j = 0; j < M && lft.size() < rows.size(); j++) {
    for (int i = lft.size(); i < rows.size(); i++)
      if (rows[i][j]) {
        swap(rows[i], rows[lft.size()]);
        break;
      }
    if (rows[lft.size()][j]) {
      for (int i = lft.size() + 1; i < rows.size(); i++) 
        rows[i] -= mul(rows[lft.size()][j], rows[i][j]) * rows[lft.size()];
      lft.push_back(j);
    }
  }
  for (auto it : rows)
    if (it.isZero(M) && it[M]) {
      puts("-1");
      return;
    }
  for (int i = (int)lft.size() - 1; i >= 0; i--) {
    clr[lft[i]] = rows[i][M];
    for (int j = lft[i] + 1; j < M; j++)
      inc(clr[lft[i]], -mul(rows[i][j], clr[j]));
    clr[lft[i]] = mul(clr[lft[i]], rows[i][lft[i]]);
  }
  for (int i = 0; i < M; i++)
    printf("%d ", clr[i] + 1);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}