#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  scanf("%d", &N);
  vector <int> a(N + 1);
  for (int i = 1; i <= N; i++)
    scanf("%d", &a[i]);
  scanf("%d", &M);
  
  long long ans = 0;
  while (M--) {
    int w, h;
    scanf("%d%d", &w, &h);
    if (a[w] > ans)
      ans = a[w];
    printf("%lld\n", ans);
    ans += h;
  }
  
  return 0;
}