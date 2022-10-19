#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    long long K;
    scanf("%d%lld", &N, &K);
    vector <int> a(N);
    for (auto &it : a)
      scanf("%d", &it);
    int maks = *max_element(a.begin(), a.end());
    int mini = *min_element(a.begin(), a.end());
    for (auto it : a)
      printf("%d ", K % 2 ? maks - it : it - mini);
    puts("");
  }
  return 0;
}