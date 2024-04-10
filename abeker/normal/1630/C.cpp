#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector <int> a(N);
  for (auto &it : a) {
    scanf("%d", &it);
    it--;
  }
  vector <int> lft(N, N), rig(N, -1);
  for (int i = 0; i < N; i++) {
    lft[a[i]] = min(lft[a[i]], i);
    rig[a[i]] = max(rig[a[i]], i);
  }
  vector <int> arcs(N + 1);
  for (int i = 0; i < N; i++)
    if (lft[i] < rig[i]) {
      arcs[lft[i]]++;
      arcs[rig[i]]--;
    }
  int ans = N, last = 0;
  for (int i = 0; i < N; i++) {
    if (!arcs[i]) {
      for (int curr = last; curr < i; ans--) {
        int nxt = 0;
        for (int j = last; j <= curr; j++)
          nxt = max(nxt, rig[a[j]]);
        last = curr;
        curr = nxt;
      }
      last = i + 1;
      ans--;
    }
    arcs[i + 1] += arcs[i];
  }
  printf("%d\n", ans);
  return 0;
}