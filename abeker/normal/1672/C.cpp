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
    int mini = N, maks = 0;
    for (int i = 1; i < N; i++)
      if (a[i] == a[i - 1]) {
        mini = min(mini, i);
        maks = max(maks, i);
      }
    printf("%d\n", mini < maks ? max(maks - mini - 1, 1) : 0);
  }
  return 0;
}