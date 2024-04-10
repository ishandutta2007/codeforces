#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 205;

int N, M;
set <int> E[MAXN];
bool bio[MAXN];

void add_edge(int u, int v) {
  E[u].insert(v);
  E[v].insert(u);
}

void erase_edge(int u, int v) {
  if (u <= N && v <= N)
    printf("%d %d\n", u, v);
  E[u].erase(v);
  E[v].erase(u);
}

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
}

void euler(int x) {
  bio[x] = true;
  while (!E[x].empty()) {
    int nxt = *E[x].begin();
    erase_edge(x, nxt);
    euler(nxt);
  }
}

void solve() {
  int sol = 0;
  for (int i = 1; i <= N; i++)
    if (E[i].size() % 2) 
      add_edge(i, N + 1);
    else 
      sol++;
      
  printf("%d\n", sol);
  memset(bio, false, sizeof bio);
  for (int i = 1; i <= N; i++)
    if (!bio[i])
      euler(i);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    load();
    solve();
  }
  return 0;
}