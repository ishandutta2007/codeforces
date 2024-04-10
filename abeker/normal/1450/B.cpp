#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int solve() {
  int N, K;
  scanf("%d%d", &N, &K);
  vector <pii> pts(N);
  for (auto &it : pts)
    scanf("%d%d", &it.first, &it.second);
  for (auto it1 : pts) {
    bool ok = true;
    for (auto it2 : pts)
      ok &= abs(it1.first - it2.first) + abs(it1.second - it2.second) <= K;
    if (ok)
      return 1;
  }
  return -1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) 
    printf("%d\n", solve());
  return 0;
}