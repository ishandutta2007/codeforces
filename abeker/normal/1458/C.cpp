#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;

int N, M;
int latin[MAXN][MAXN];
int ans[MAXN][MAXN];
char op[MAXM];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", latin[i] + j);
      latin[i][j]--;
    }
  scanf("%s", op);
}

inline int add(int x, int y) {
  x += y;
  if (x >= N)
    return x - N;
  if (x < 0)
    return x + N;
  return x;
}

inline void inc(int &x) {
  x = add(x, 1);
}

inline void dec(int &x) {
  x = add(x, -1);
}

void solve() {
  vector <int> perm(3), shift(3);
  iota(perm.begin(), perm.end(), 0);
  for (int i = 0; i < M; i++)
    if (op[i] == 'R')
      inc(shift[1]);
    else if (op[i] == 'L')
      dec(shift[1]);
    else if (op[i] == 'D')
      inc(shift[0]);
    else if (op[i] == 'U')
      dec(shift[0]);
    else if (op[i] == 'I') {
      swap(shift[1], shift[2]);
      swap(perm[1], perm[2]);
    }
    else {
      swap(shift[0], shift[2]);
      swap(perm[0], perm[2]);
    }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      vector <int> nxt(3);
      for (int k = 0; k < 3; k++)
        nxt[k] = add(vector <int>{i, j, latin[i][j]}[perm[k]], shift[k]);   
      ans[nxt[0]][nxt[1]] = nxt[2]; 
    }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%d ", ++ans[i][j]);
    puts("");
  }
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