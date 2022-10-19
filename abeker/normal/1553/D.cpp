#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
char s[MAXN], t[MAXN];

bool solve() {
  scanf("%s%s", s, t);
  N = strlen(s);
  M = strlen(t);
  int pos = 0;
  for (int i = 0; i < M; i++) {
    while (pos < N && (s[pos] != t[i] || (pos + i + M + N) % 2))
      pos++;
    if (pos >= N)
      return false;
  }
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) 
    puts(solve() ? "YES" : "NO");
  return 0;
}