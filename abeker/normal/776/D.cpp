#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
int r[MAXN];
vector <int> who[MAXN];
vector <pii> E[MAXN];
int color[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", r + i);
  for (int i = 1; i <= M; i++) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int x;
      scanf("%d", &x);
      who[x].push_back(i);
    }
  }
}

void add_edge(int a, int b, int c) {
  E[a].push_back(pii(b, c));
  E[b].push_back(pii(a, c));
}

bool dfs(int x, int c) {
  if (color[x] != -1)
    return color[x] == c;
  color[x] = c;
  for (int i = 0; i < E[x].size(); i++)
    if (!dfs(E[x][i].first, c ^ E[x][i].second ^ 1))
      return false;
  return true;
}

bool solve() {
  for (int i = 1; i <= N; i++)
    add_edge(who[i][0], who[i][1], r[i]);
  
  memset(color, -1, sizeof color);
  for (int i = 1; i <= M; i++)
    if (color[i] == -1 && !dfs(i, 0))
      return false;
  
  return true;
}

int main() {
  load();
  puts(solve() ? "YES" : "NO");
  return 0;
}