#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    set <int> all;
    for (int i = 0; i < N; i++) {
      int x;
      scanf("%d", &x);
      all.insert(x);
    }
    printf("%d\n", all.size() == 1 ? N : 1);
  }
  return 0;
}