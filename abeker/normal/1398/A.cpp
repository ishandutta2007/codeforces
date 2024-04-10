#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    vector <int> a(N);
    for (auto &it : a)
      scanf("%d", &it);
    if (a[0] + a[1] <= a[N - 1])
      printf("1 2 %d\n", N);
    else
      puts("-1");
  }
  return 0;
}