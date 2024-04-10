#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 300005

using namespace std;
typedef long long ll;
int t, n, a[maxn], cnt[maxn];
vector<int> ans;
bool vis[maxn];
int mex() { // O(n)
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) cnt[a[i]]++;
  int res = 0;
  while (cnt[res]) res++;
  return res;
}
void solve() {
  ans.clear();
  memset(vis, 0, sizeof(vis));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  while (mex() < n) {
    int x = mex();
    ans.push_back(x + 1); 
    a[x + 1] = x;
  }
  // Now, it's a permutation.
  for (int i = 1; i <= n; i++) {
    int j = a[i] + 1;
    if (j == i || vis[i]) continue;
    vis[i] = true;
    ans.push_back(i);
    while (j != i) {
      vis[j] = true;
      ans.push_back(j);
      j = a[j] + 1;
    }
    ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (auto i : ans) {
    printf("%d ", i);
  }
  puts("");
}
int main() {
  scanf("%d", &t); 
  while (t--) solve();
  return 0;
}