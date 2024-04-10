#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;

int N, M, K;
int pot[MAXN];
int row[MAXN][2], col[MAXN][2];
int empty_rows, empty_cols;
int bad_rows, bad_cols;
map <pii, int> mat;
int cnt[2];

bool isFull(int* arr) {
  return arr[0] && arr[1];
}

bool isEmpty(int* arr) {
  return !arr[0] && !arr[1];
}

void remove_cell(int x, int y) {
  auto it = mat.find({x, y});
  if (it == mat.end())
    return;
  row[x][(it -> second + y) % 2]--;
  col[y][(it -> second + x) % 2]--;
  cnt[(it -> second + x + y) % 2]--;
  empty_rows += isEmpty(row[x]);
  empty_cols += isEmpty(col[y]);
  mat.erase(it);
}

void add_cell(int x, int y, int v) {
  empty_rows -= isEmpty(row[x]);
  empty_cols -= isEmpty(col[y]);
  row[x][(v + y) % 2]++;
  col[y][(v + x) % 2]++;
  cnt[(v + x + y) % 2]++;
  mat[{x, y}] = v;
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  empty_rows = N;
  empty_cols = M;
  pot[0] = 1;
  for (int i = 1; i <= N || i <= M; i++)
    pot[i] = add(pot[i - 1], pot[i - 1]);
  while (K--) {
    int x, y, t;
    scanf("%d%d%d", &x, &y, &t);
    bad_rows -= isFull(row[x]);
    bad_cols -= isFull(col[y]);
    remove_cell(x, y);
    if (t != -1) 
      add_cell(x, y, t);
    bad_rows += isFull(row[x]);
    bad_cols += isFull(col[y]);
    printf("%d\n", add(add(bad_rows ? 0 : pot[empty_rows], bad_cols ? 0 : pot[empty_cols]), -count(cnt, cnt + 2, 0)));
  }
  return 0;
}