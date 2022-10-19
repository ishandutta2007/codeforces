#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  if (!n)
    return;
  int x = ceil(sqrt(n - 1));
  int m = x * x - n + 1;
  solve(m);
  for (int i = m; i < n; i++)
    printf("%d ", m + n - 1 - i);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    solve(N);
    puts("");
  }
  return 0;
}