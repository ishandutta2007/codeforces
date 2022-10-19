#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <vector <int>> a;

void load() {
  scanf("%d%d", &N, &M);
  a = vector <vector <int>> (N, vector <int> (M));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%d", &a[i][j]);
}

bool is_sorted() {
  for (int i = 0; i < N; i++)
    for (int j = 1; j < M; j++)
      if (a[i][j - 1] > a[i][j])
        return false;
  return true;
}

void swap_columns(int c1, int c2) {
  for (int i = 0; i < N; i++)
    swap(a[i][c1], a[i][c2]);
}

void solve() {
  if (is_sorted()) {
    puts("1 1");
    return;
  }
  for (int i = 0; i < N; i++) {
    vector <int> tmp = a[i];
    sort(tmp.begin(), tmp.end());
    vector <int> diff;
    for (int j = 0; j < M; j++)
      if (tmp[j] != a[i][j])
        diff.push_back(j);
    assert(diff.size() != 1);
    if (!diff.empty()) {
      swap_columns(diff[0], diff[1]);
      if (is_sorted())
        printf("%d %d\n", diff[0] + 1, diff[1] + 1);
      else
        puts("-1");
      return;
    }
  }
  assert(false);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}