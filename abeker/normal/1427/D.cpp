#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

int N;
int perm[MAXN];
vector <vector <int>> ans;

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", perm + i);
}

void apply(vector <int> d) {
  int st = 1;
  vector <vector <int>> blocks;
  vector <int> non_zero;
  for (auto it : d) 
    if (it) {
      non_zero.push_back(it);
      blocks.push_back(vector <int> (perm + st, perm + st + it));
      st += it;
    }
  st = 0;
  reverse(blocks.begin(), blocks.end());
  for (auto it : blocks)
    for (auto elem : it)
      perm[++st] = elem;
  ans.push_back(non_zero);
}

void solve() {
  while (1) {
    bool ok = false;
    vector <int> pos(N + 2);
    for (int i = 1; i <= N; i++) {
      int j = i;
      for (; j <= N && perm[j] - perm[i] == j - i; j++);
      int tmp = pos[perm[--j] + 1];
      if (tmp) {
        apply({tmp - 1, i - tmp, j - i + 1, N - j});
        ok = true;
        break;
      }
      pos[perm[i]] = i;
    }
    if (!ok)
      break;
  }
  assert(ans.size() <= N);
  for (int i = 1; i <= N; i++)
    assert(perm[i] == i);
  printf("%d\n", ans.size());
  for (auto it : ans) {
    printf("%d", it.size());
    for (auto elem : it)
      printf(" %d", elem);
    puts("");
  }
}

int main() {  
  load();
  solve();
  return 0;
}