#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int A, B;
    scanf("%d%d", &A, &B);
    if (A > B)
      swap(A, B);
    set <int> ans;
    for (int i = 0; i < 2; i++) {
      int tmp = (A + B + i) / 2;
      for (int j = 0; j <= A; j++)
        ans.insert(A + tmp - 2 * j);
    }
    printf("%d\n", ans.size());
    for (auto it : ans)
      printf("%d ", it);
    puts("");
  }
  return 0;
}