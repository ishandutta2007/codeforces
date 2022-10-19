#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  scanf("%d", &N);
  vector <int> p(N + 1);
  auto ask = [&](int x) {
    printf("? %d\n", x);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
  };
  for (int i = 1; i <= N; i++)
    if (!p[i]) {
      vector <int> cycle;
      while (1) {
        int tmp = ask(i);
        if (!cycle.empty() && tmp == cycle[0])
          break;
        cycle.push_back(tmp);
      }
      int sz = cycle.size();
      for (int j = 0; j < sz; j++)
        p[cycle[j]] = cycle[(j + 1) % sz];
    }
  printf("!");
  for (int i = 1; i <= N; i++)
    printf(" %d", p[i]);
  puts("");
  fflush(stdout);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}