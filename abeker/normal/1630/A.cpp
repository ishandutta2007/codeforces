#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K;
  scanf("%d%d", &N, &K);
  if (N == 4 && K == 3) {
    puts("-1");
    return;
  }
  vector <int> other(N);
  auto make_edge = [&](int x, int y) {
    other[x] = y;
    other[y] = x;
  };
  auto comp = [&](int x) {
    return x ^ N - 1;
  };
  for (int i = 0; i < N / 2; i++)
    make_edge(i, comp(i));
  if (K == N - 1) {
    int n = __builtin_ctz(N);
    for (int i = 0; i < n; i++) 
      make_edge(1 << i, comp(1 << (i + 1) % n));
  }
  else {
    make_edge(0, comp(K));
    make_edge(K, N - 1);
  }
  for (int i = 0; i < N; i++)
    if (i < other[i])
      printf("%d %d\n", i, other[i]);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) 
    solve();
  return 0;
}