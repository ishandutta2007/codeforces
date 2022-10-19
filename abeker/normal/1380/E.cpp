#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
set <int> on[MAXN];
int idx[MAXN];
int tot;

void join(int x, int y) {
  int &wx = idx[x];
  int &wy = idx[y];
  if (on[wx].size() < on[wy].size()) 
    swap(wx, wy);
  for (auto it : on[wy]) {
    tot += on[wx].count(it - 1);
    tot += on[wx].count(it + 1);
  }
  for (auto it : on[wy])
    on[wx].insert(it);  
}

void query() {
  printf("%d\n", N - 1 - tot);
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    int tower;
    scanf("%d", &tower);
    on[tower].insert(i);
  }
  
  for (int i = 1; i <= M; i++) {
    idx[i] = i;
    int prev = -1;
    for (auto it : on[i]) {
      tot += it == prev + 1;
      prev = it;
    }
  }
  
  query();
  for (int i = 1; i < M; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    join(a, b);
    query();
  }
  
  return 0;
}