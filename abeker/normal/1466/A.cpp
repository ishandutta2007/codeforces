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
    set <int> all;
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++)
        all.insert(x[j] - x[i]);
    printf("%d\n", all.size());
  }
  return 0;
}