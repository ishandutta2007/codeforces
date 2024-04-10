#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int INF = 1e9;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    pii lft = {INF, INF};
    pii rig = {0, INF};
    pii maks = {0, INF};
    while (N--) {
      int l, r, c;
      scanf("%d%d%d", &l, &r, &c);
      lft = min(lft, pii(l, c));
      rig = min(rig, pii(-r, c));
      maks = min(maks, pii(l - r - 1, c));
      int ans = lft.second + rig.second;
      if (maks.first == lft.first + rig.first - 1)
        ans = min(ans, maks.second);
      printf("%d\n", ans);
    }
  }
  return 0;
}