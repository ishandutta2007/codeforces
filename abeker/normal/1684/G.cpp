#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N, M;
int t[MAXN];
vector <int> adj[MAXN];
int match[MAXN];
bool bio[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d", t + i);
}

bool dfs(int x) {
  if (x == -1)
    return true;
  if (bio[x])
    return false;
  bio[x] = true;
  for (auto it : adj[x])
    if (dfs(match[it])) {
      match[it] = x;
      return true;
    }
  return false;
}

void solve() {
  vector <int> large, small;
  for (int i = 0; i < N; i++)
    if (t[i] > M / 3)
      large.push_back(i);
    else
      small.push_back(i);
  for (auto it1 : large)
    for (auto it2 : small)
      if (!(t[it1] % t[it2]) && 2 * t[it1] + t[it2] <= M)
        adj[it1].push_back(it2);
  memset(match, -1, sizeof match);
  for (auto it : large) {
    memset(bio, false, sizeof bio);
    if (!dfs(it)) {
      puts("-1");
      return;
    }
  }
  printf("%d\n", small.size());
  for (auto it : small) {
    if (match[it] == -1)
      match[it] = it;
    printf("%d %d\n", 2 * t[match[it]] + t[it], t[match[it]] + t[it]);
  }
}

int main() {
  load();
  solve();
  return 0;
}