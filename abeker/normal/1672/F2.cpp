#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN], b[MAXN];
vector <int> pos_a[MAXN], pos_b[MAXN];
vector <int> adj[2 * MAXN];
int bio[2 * MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
}

void process(int* arr, vector <int>* pos_arr) {
  for (int i = 1; i <= N; i++)
    pos_arr[i].clear();
  for (int i = 1; i <= N; i++)
    pos_arr[arr[i]].push_back(i);
}

void add_edge(int x, int y) {
  adj[x].push_back(y);
}

bool dfs(int x) {
  if (bio[x])
    return bio[x] - 1;
  bio[x] = 1;
  for (auto it : adj[x])
    if (!dfs(it))
      return false;
  bio[x] = 2;
  return true;
}

bool solve() {
  process(a, pos_a);
  process(b, pos_b);
  for (int i = 1; i <= 2 * N; i++) {
    adj[i].clear();
    bio[i] = 0;
  }
  int maks = 0;
  for (int i = 1; i <= N; i++) {
    for (auto it : pos_a[i])
      add_edge(it, i + N);
    for (auto it : pos_b[i])
      add_edge(i + N, it);
    if (pos_a[i].size() > pos_a[maks].size())
      maks = i;
  }
  for (auto it : pos_a[maks])
    bio[it] = 2;
  for (int i = 1; i <= N; i++)
    if (!dfs(i))
      return false;
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    puts(solve() ? "AC" : "WA");
  }
  return 0;
}