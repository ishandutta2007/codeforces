#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int N;
  scanf("%d", &N);
  vector <int> a(N);
  for (auto &it : a)
    scanf("%d", &it);
  int pos = max_element(a.begin(), a.end()) - a.begin();
  for (int i = 1; i < N; i++)
    if ((i <= pos && a[i - 1] > a[i]) || (i > pos && a[i - 1] < a[i]))
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