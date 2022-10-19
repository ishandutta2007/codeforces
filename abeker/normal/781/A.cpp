#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N;
vector <int> E[MAXN];
int color[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    E[x].push_back(y);
    E[y].push_back(x);
  }
}

void dfs(int x, int p) {
  int c1 = color[p];
  int c2 = color[x];
  if (c1 > c2)
    swap(c1, c2);
  int tmp = 0;
  for (int i = 0; i < E[x].size(); i++) {
    int nxt = E[x][i];
    if (nxt == p)
      continue;
    if (tmp == c1)
      tmp++;
    if (tmp == c2)
      tmp++;
    color[nxt] = tmp++;
  }
  for (int i = 0; i < E[x].size(); i++)
    if (E[x][i] != p)
      dfs(E[x][i], x);
}

void solve() {
  int sol = 0;
  for (int i = 1; i <= N; i++)
    sol = max(sol, (int)E[i].size() + 1);
  
  printf("%d\n", sol);
  dfs(1, 0);
  for (int i = 1; i <= N; i++)
    printf("%d ", ++color[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}