#include <bits/stdc++.h>
using namespace std;

int solve() {
  int N, M;
  scanf("%d%d", &N, &M);
  vector <int> inf(M);
  for (auto &it : inf)
    scanf("%d", &it);
  sort(inf.begin(), inf.end());
  vector <int> sorted = {inf[0] - 1 + N - inf.back()};
  for (int i = 1; i < M; i++)
    sorted.push_back(inf[i] - inf[i - 1] - 1);
  sort(sorted.begin(), sorted.end(), greater <int> ());
  int timer = 0;
  for (auto it : sorted)
    if (2 * timer < it) {
      M += timer;
      if (2 * timer + 2 < it)
        M += ++timer;
      else
        M += it - timer - 1;
      timer++;
    }
    else
      M += it;
  return M;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%d\n", solve());
  return 0;
}