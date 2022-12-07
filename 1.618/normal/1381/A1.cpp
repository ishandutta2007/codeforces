#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 100005

using namespace std;
typedef long long ll;
int n;
char s[maxn], t[maxn];
void solve() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    // t[n - i + 1]
    int pos = (i & 1 ? i / 2 + 1 : n - i / 2 + 1);
    int cur = ((i - 1) & 1) ? '1' - s[pos] : s[pos] - '0';
    if (cur + '0' == t[n - i + 1]) ans.push_back(1);
    ans.push_back(n - i + 1);
  }
  printf("%d ", int(ans.size()));
  for (auto i : ans) printf("%d ", i);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}