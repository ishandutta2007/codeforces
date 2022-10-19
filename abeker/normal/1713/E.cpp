#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> pii;
 
const int MAXN = 1e3 + 5;
 
int N;
int a[MAXN][MAXN];
int dad[MAXN], rnk[MAXN], clr[MAXN];
 
int next_int() {
  int res = 0;
  int d = getchar();
  while (d < 48 || d > 57) 
    d = getchar();
  do {
    res = res * 10 + d - 48;
    d = getchar();
  } while (d > 47 && d < 58);
  return res;
}

void load() {
  N = next_int();
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      a[i][j] = next_int();
}
 
pii find(int x) {
  if (dad[x] == x)
    return {x, 0};
  pii tmp = find(dad[x]);
  return {dad[x] = tmp.first, clr[x] ^= tmp.second};
}
 
bool join(int x, int y, int c) {
  pii root_x = find(x);
  pii root_y = find(y);
  int diff = root_x.second ^ root_y.second ^ c;
  if (root_x.first == root_y.first)
    return diff;
  if (rnk[root_x.first] > rnk[root_y.first])
    swap(root_x, root_y);
  dad[root_x.first] = root_y.first;
  rnk[root_y.first] += rnk[root_x.first] == rnk[root_y.first];
  clr[root_x.first] = diff;
  return false;
}
 
void solve() {
  for (int i = 0; i < N; i++) {
    rnk[i] = clr[i] = 0;
    dad[i] = i;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i < j && a[i][j] != a[j][i]) {
        bool ch = a[i][j] > a[j][i];
        ch ^= join(i, j, ch);
        if (ch)
          swap(a[i][j], a[j][i]);
      }
      printf("%d ", a[i][j]);
    }
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