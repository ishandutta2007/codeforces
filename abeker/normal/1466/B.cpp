#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    vector <int> x(N);
    for (auto &it : x)
      scanf("%d", &it);
    for (int i = 1; i < N; i++)
      if (x[i] <= x[i - 1])
        x[i]++;
    set <int> all;
    for (auto it : x)
      all.insert(it);
    printf("%d\n", all.size());
  }
  return 0;
}