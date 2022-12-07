#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 1005
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, a[maxn], k, nxt[maxn];
P p[maxn]; // for reassignment
vector<P> ans;
void work(int x) {
  memset(nxt, 0, sizeof(nxt));
  for (int i = 1; i < x; i++) {
    if (a[i] > a[x]) nxt[a[i] - 1] = i;
  }
  while (a[x] != x) {
    ans.push_back(mp(nxt[a[x]], x));
    swap(a[ans.back().first], a[ans.back().second]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[i] = mp(a[i], i);
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    a[p[i].second] = ++k;
  }
  for (int i = n; i >= 1; i--) work(i);
  printf("%d\n", (int)ans.size());
  for (auto i : ans) {
    printf("%d %d\n", i.first, i.second);
  }
  return 0;
}