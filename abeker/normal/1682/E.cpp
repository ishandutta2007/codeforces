#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N, M;
int p[MAXN];
int a[MAXN], b[MAXN];
deque <pii> adj[MAXN];
int idx[MAXN], nxt[MAXN];
set <int> active;

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", p + i);
  for (int i = 0; i < M; i++)
    scanf("%d%d", a + i, b + i);
}

void update(int x) {
  if (!adj[x].empty()) {
    nxt[x] = adj[x].front().first;
    if (nxt[nxt[x]] == x)
      active.insert(adj[x].front().second);
  }
}

void solve() {
  int curr = 0;
  for (int i = 1; i <= N; i++)
    for (int j = i; !idx[j]; j = p[j])
      idx[j] = ++curr;
  for (int i = 0; i < M; i++) {
    a[i] = idx[a[i]];
    b[i] = idx[b[i]];
    adj[a[i]].push_back({b[i], i});
    adj[b[i]].push_back({a[i], i});
  }
  for (int i = 1; i <= N; i++) {
    sort(adj[i].begin(), adj[i].end());
    for (int j = 0; j < adj[i].size(); j++)
      if (adj[i][j].first > i) {
        rotate(adj[i].begin(), adj[i].begin() + j, adj[i].end());
        break;
      }
    update(i);
  }
  for (int i = 0; i < M; i++) {
    int tmp = *active.begin();
    printf("%d ", tmp + 1);
    active.erase(tmp);
    adj[a[tmp]].pop_front();
    adj[b[tmp]].pop_front();
    update(a[tmp]);
    update(b[tmp]);
  }
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}