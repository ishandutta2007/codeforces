#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int cnt[2][2];

ll get(int mask) {
  return cnt[mask / 2][mask % 2];
}

int main() {
  scanf("%d", &N);
  ll ans = (ll)N * (N - 1) * (N - 2) / 6;
  while (N--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x /= 2;
    y /= 2;
    cnt[x % 2][y % 2]++;
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < i; j++)
      for (int k = 0; k < j; k++)
        ans -= get(i) * get(j) * get(k);
  printf("%lld\n", ans);
  return 0;
}