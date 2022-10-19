#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ask(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  ll ans;
  scanf("%lld", &ans);
  return ans;
}

int invert(ll x) {
  return (1 + sqrt(8 * x + 1)) / 2;
}

void solve() {
  int N;
  scanf("%d", &N);
  int lo = 1, hi = N;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ask(1, mid))
      hi = mid - 1;
    else
      lo = mid;
  }
  int j = lo + ask(lo, N) - ask(lo + 1, N) + 1;
  int k = j + invert(ask(j, N)) - 1;
  printf("! %d %d %d\n", lo, j, k);
  fflush(stdout);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}