#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int N, K;
  scanf("%d%d", &N, &K);
  vector <int> a(N);
  for (auto &it : a)
    scanf("%d", &it);
  sort(a.begin(), a.end());
  for (auto it : a)
    if (binary_search(a.begin(), a.end(), it + K))
      return true;
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "YES" : "NO");
  return 0;
}