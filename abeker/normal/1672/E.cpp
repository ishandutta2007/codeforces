#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

int N;
ll ans = INF;

int ask(int width) {
  printf("? %d\n", width);
  fflush(stdout);
  int height;
  scanf("%d", &height);
  if (height)
    ans = min(ans, (ll)height * width);
  return height;
}

int main() {
  scanf("%d", &N);
  int lo = 1, hi = INF;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (ask(mid) == 1)
      hi = mid;
    else
      lo = mid + 1;
  }
  for (int h = 1; h <= N; h++) 
    ask(lo / h);
  printf("! %lld\n", ans);
  return 0;
}