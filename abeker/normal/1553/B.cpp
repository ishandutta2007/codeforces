#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;

int N, M;
char s[MAXN], t[2 * MAXN];

void load() {
  scanf("%s%s", s, t);
}

bool solve() {
  N = strlen(s);
  M = strlen(t);
  for (int i = 0; i < N; i++)
    for (int j = 0; i + j < N && j < M && s[i + j] == t[j]; j++) {
      bool ok = true;
      for (int k = 1; k < M - j; k++)
        ok &= k <= i + j && s[i + j - k] == t[j + k];
      if (ok)
        return true;
    }
  return false;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}