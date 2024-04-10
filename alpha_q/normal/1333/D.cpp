#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int M = 3000010;

char s[N];
int n, k, pos[N];
vector <int> ans[M];

int main() {
  cin >> n >> k;
  scanf("%s", s + 1);
  int rs = 0, tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'R') ++rs;
    else tot += rs;
  }
  if (k > tot) {
    puts("-1");
    return 0;
  }
  int rem = k, at = 0;
  while (rem--) {
    int sz = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] == 'R' and s[i + 1] == 'L') {
        pos[sz++] = i;
      }
    }
    if (tot - sz > rem) {
      ans[++at].resize(sz);
      tot -= sz;
      for (int i = 0; i < sz; ++i) ans[at][i] = pos[i];
      for (int i = 0; i < sz; ++i) swap(s[pos[i]], s[pos[i] + 1]);
    } else {
      int cur = tot - rem;
      ans[++at].resize(cur);
      for (int i = 0; i < cur; ++i) ans[at][i] = pos[i];
      for (int i = 0; i < cur; ++i) swap(s[pos[i]], s[pos[i] + 1]);
      break;
    }
  }
  if (rem > 0) while (rem > 0) {
    for (int i = 1; i < n; ++i) if (s[i] == 'R' and s[i + 1] == 'L') {
      ans[++at].emplace_back(i); swap(s[i], s[i + 1]); --rem;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'R' and s[i + 1] == 'L') {
      puts("-1"); return 0;
    }
  }
  for (int i = 1; i <= k; ++i) {
    printf("%d", (int) ans[i].size());
    for (int x : ans[i]) printf(" %d", x);
    puts("");
  }
  return 0;
}