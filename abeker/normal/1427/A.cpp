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
    int sum = accumulate(a.begin(), a.end(), 0);
    if (!sum) {
      puts("NO");
      continue;
    }
    if (sum < 0)
      sort(a.begin(), a.end());
    else
      sort(a.begin(), a.end(), greater <int> ());
    puts("YES");
    for (auto it : a)
      printf("%d ", it);
    puts("");
  }
  return 0;
}