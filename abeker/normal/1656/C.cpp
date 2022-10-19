#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N);
  for (auto &it : a)
    scanf("%d", &it);
  if (!count(a.begin(), a.end(), 1))
    return true;
  sort(a.begin(), a.end());
  for (int i = 1; i < N; i++)
    if (a[i] == a[i - 1] + 1)
      return false;
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "YES" : "NO");
  return 0;
}