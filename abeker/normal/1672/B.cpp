#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
char s[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%s", s);
    N = strlen(s);
    int pref = 0;
    bool ok = s[N - 1] == 'B';
    for (int i = 0; i < N; i++) {
      pref += s[i] == 'A' ? 1 : -1;
      ok &= pref >= 0;
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}