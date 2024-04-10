#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e3 + 5;

int N;
int a[MAXN];
int perm[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

void solve() {
  for (int i = 0; i < N; i++)
    perm[i] = i;
  
  sort(perm, perm + N, [](int x, int y) { return a[x] == a[y] ? x < y : a[x] < a[y]; });
  
  vector <pii> ans;
  for (int i = 0; i < N; i++) {
    int pos = -1;
    for (int j = 0; j < N; j++)
      if (perm[j] == i)
        pos = j;
    for (int j = pos; j > i; j--) {
      ans.push_back({perm[j], perm[j - 1]});
      swap(perm[j], perm[j - 1]);
    }
  }
  
  printf("%d\n", ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first + 1, it.second + 1);
}

int main() {
  load();
  solve();
  return 0;
}