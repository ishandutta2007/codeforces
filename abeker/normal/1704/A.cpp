#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int N, M;
  char a[55], b[55];
  scanf("%d%d%s%s", &N, &M, a, b);
  for (int i = 1; i < M; i++)
    if (a[i + N - M] != b[i])
      return false;
  for (int i = 0; i <= N - M; i++)
    if (a[i] == b[0])
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