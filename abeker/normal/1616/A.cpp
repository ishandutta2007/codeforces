#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    map <int, int> cnt;
    while (N--) {
      int x;
      scanf("%d", &x);
      cnt[abs(x)]++;
    }
    int ans = cnt.size();
    for (auto it : cnt)
      ans += it.first && it.second > 1;
    printf("%d\n", ans);
  }
  return 0;
}