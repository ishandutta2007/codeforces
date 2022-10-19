#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int N;
char mat[MAXN][MAXN];
char ans[MAXN][MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%s", mat[i]);
}

void solve() {
  for (int k = 0; k < 3; k++)
    for (int l = 0; l < 3; l++)
      if (k != l) {
        int changes = 0, tot = 0;
        for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++) {
            ans[i][j] = mat[i][j];
            if (mat[i][j] == '.')
              continue;
            int clr = (i + j) % 3;
            if (clr == k)
              ans[i][j] = 'X';
            else if (clr == l)
              ans[i][j] = 'O';
            changes += ans[i][j] != mat[i][j];
            tot++;
          }
        if (changes <= tot / 3) {
          for (int i = 0; i < N; i++) {
            ans[i][N] = '\0';
            puts(ans[i]);
          }
          return;
        }
      }
  assert(false);
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