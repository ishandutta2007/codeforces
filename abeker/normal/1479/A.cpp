#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

int solve(int lo, int hi) {
  if (hi - lo == 1)
    return lo;
  int mid = (lo + hi) / 2;
  return ask(mid) > ask(mid - 1) ? solve(lo, mid) : solve(mid, hi);
}

int main() {
  int N;
  scanf("%d", &N);
  printf("! %d\n", solve(1, N + 1));
  return 0;
}