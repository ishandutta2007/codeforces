#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

char s[N];
vector <int> yo[N];
int t, n, k, p[N], cnt[28];

inline int find (int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

inline void unite (int x, int y) {
  x = find(x), y = find(y);
  if (rand() & 1) swap(x, y);
  if (x ^ y) p[x] = y;
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d %s", &n, &k, s + 1);
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 1; i <= n - k; ++i) unite(i, i + k);
    for (int i = 1, j = n; i < j; ++i, --j) unite(i, j);
    for (int i = 1; i <= n; ++i) yo[i].clear();
    for (int i = 1; i <= n; ++i) yo[find(i)].emplace_back(i);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      memset(cnt, 0, sizeof cnt);
      for (int x : yo[i]) ++cnt[s[x] - 'a'];
      int mx = 0;
      for (int j = 0; j < 26; ++j) mx = max(mx, cnt[j]);
      ans += (yo[i].size() - mx);
    }
    printf("%d\n", ans);
  }
  return 0;
}