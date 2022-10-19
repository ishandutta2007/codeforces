#include <bits/stdc++.h>
using namespace std;

int solve() {
  int N, K;
  scanf("%d%d", &N, &K);
  set <int> vals;
  while (N--) {
    int x;
    scanf("%d", &x);
    vals.insert(x);
  }
  int diff = vals.size();
  if (diff == 1)
    return 1;
  if (K == 1)
    return -1;
  return ceil((double)(diff - 1) / (K - 1));
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) 
    printf("%d\n", solve());
  return 0;
}