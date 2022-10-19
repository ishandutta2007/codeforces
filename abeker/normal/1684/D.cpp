#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N, K;
    scanf("%d%d", &N, &K);
    vector <int> a(N);
    for (auto &it : a)
      scanf("%d", &it);
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    vector <int> sorted;
    for (int i = 0; i < N; i++)
      sorted.push_back(a[i] + i + 1 - N);
    sort(sorted.begin(), sorted.end(), greater <int> ());
    ll curr = 0, maks = 0;
    for (int i = 0; i < K; i++) {
      curr += sorted[i] + i;
      maks = max(maks, curr);
    }
    printf("%lld\n", sum - maks);
  }
  return 0;
}