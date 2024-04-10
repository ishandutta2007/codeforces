#include <bits/stdc++.h>
using namespace std;

typedef unordered_set <int> uset;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];
vector <int> adj[MAXN];
int ans;

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

uset* dfs(int x, int p) {
  a[x] ^= a[p];
  vector <uset*> ch;
  for (auto it : adj[x])
    if (it != p)
      ch.push_back(dfs(it, x));
  if (ch.empty())
    return new uset({a[x]});
  swap(*max_element(ch.begin(), ch.end(), [&](const uset* p1, const uset* p2) { return p1 -> size() < p2 -> size(); }), *ch.begin());
  bool ok = false;
  for (int i = 1; i < ch.size(); i++) {
    for (auto it : *ch[i])
      ok |= ch[0] -> count(it ^ a[x] ^ a[p]);
    for (auto it : *ch[i])
      ch[0] -> insert(it);
  }
  ok |= ch[0] -> count(a[p]);
  ch[0] -> insert(a[x]);
  if (ok) {
    ch[0] -> clear();
    ans++;
  }
  return ch[0];
}

int main() {
  load();
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}