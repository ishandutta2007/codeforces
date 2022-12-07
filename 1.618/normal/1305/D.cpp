#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 1005

using namespace std;
typedef long long ll;

int ask(int u, int v) {
  printf("? %d %d\n", u, v);
  fflush(stdout);
  int w;
  scanf("%d", &w);
  if(w == -1) exit(0);
  return w;
}
void guess(int u) {
  printf("! %d\n", u);
  fflush(stdout);
  exit(0);
}
int n, x[maxn], y[maxn];
vector<int> adj[maxn], leaves;
bool del[maxn];
void removeLeaves(){
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i < n; i++) {
    if (!del[x[i]] && !del[y[i]]) {
      adj[x[i]].push_back(y[i]);
      adj[y[i]].push_back(x[i]);
    }
  }
  leaves.clear();
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1) leaves.push_back(i);
  }
  int u = leaves.front(), v = leaves.back();
  int w = ask(u, v);
  if(u == w) guess(u);
  if(v == w) guess(v);
  del[u] = del[v] = true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n / 2; i++) removeLeaves();
  for (int i = 1; i <= n; i++) if (!del[i]) guess(i);
  return 0;
}