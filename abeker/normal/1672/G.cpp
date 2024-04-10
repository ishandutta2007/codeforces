#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e3 + 5;
const int MOD = 998244353;

class UnionFind {
  int n, m;
  vector <int> dad, rnk, parity;
public:
  int find(int x) {
    return dad[x] == x ? x : dad[x] = find(dad[x]);
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
    parity[y] ^= parity[x];
  }
  UnionFind(vector <int> parity, vector <pii> edges) : parity(parity) {
    n = parity.size();
    m = edges.size();
    dad.resize(n);
    iota(dad.begin(), dad.end(), 0);
    rnk.resize(n);
    for (auto it : edges)
      join(it.first, it.second);
  }
  int calc() {
    int res = m - n;
    for (int i = 0; i < n; i++)
      if (find(i) == i) {
        if (parity[i])
          return -1;
        res++;
      }
    return res;
  }
};

int N, M;
char mat[MAXN][MAXN];
int row[MAXN], col[MAXN];
bool has_row[MAXN], has_col[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%s", mat[i]);
}

inline void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
}

int pow2(int n) {
  int res = 1;
  while (n--)
    add(res, res);
  return res;
}

int solve() {
  vector <pii> edges;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (mat[i][j] == '?') {
        edges.push_back({i, j + N});
        has_row[i] = true;
        has_col[j] = true;
      }
      else {
        int tmp = mat[i][j] - '0';
        row[i] ^= tmp;
        col[j] ^= tmp;
      }
  if (!(N % 2) && !(M % 2))
    return pow2(edges.size());
  if (N % 2 && M % 2) {
    int sol = 0;
    for (int k = 0; k < 2; k++)
      for (int l = 0; l < 2; l++) {
        vector <int> parity;
        for (int i = 0; i < N; i++)
          parity.push_back(row[i] ^ k);
        for (int j = 0; j < M; j++)
          parity.push_back(col[j] ^ l);
        UnionFind graph(parity, edges); 
        int ex = graph.calc();
        add(sol, ex == -1 ? 0 : pow2(ex));
      }
    return sol;
  }
  set <int> sums;
  int ex = edges.size();
  if (!(N % 2))
    for (int i = 0; i < N; i++)
      if (has_row[i])
        ex--;
      else
        sums.insert(row[i]);
  if (!(M % 2)) 
    for (int j = 0; j < M; j++)
      if (has_col[j])
        ex--;
      else
        sums.insert(col[j]);
  return sums.size() == 2 ? 0 : pow2(ex + sums.empty());
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}