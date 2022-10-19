#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  scanf("%d", &N);
  vector <int> perm(N);
  for (auto &it : perm)
    scanf("%d", &it);
  for (int i = 1; i < N - 1; i++)
    if (perm[i - 1] < perm[i] && perm[i] > perm[i + 1]) {
      printf("YES\n%d %d %d\n", i, i + 1, i + 2);
      return;
    }
  puts("NO");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}