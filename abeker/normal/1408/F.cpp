#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int pot = 1;
  while (pot <= N / 2)
    pot *= 2;
  vector <pair <int, int>> ans;
  function <void(int, int)> equalize = [&](int lo, int hi) {
    if (hi - lo == 1)
      return;
    int mid = (lo + hi) / 2;
    equalize(lo, mid);
    equalize(mid, hi);
    for (int i = lo; i < mid; i++)
      ans.push_back({i, i + mid - lo});
  };
  equalize(0, pot);
  equalize(N - pot, N);
  printf("%d\n", ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first + 1, it.second + 1);
  return 0;
}