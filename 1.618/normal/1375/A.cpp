#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 105
using namespace std;
typedef long long ll;
int t, n, a[maxn];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i & 1) printf("%d ", -abs(a[i]));
    else printf("%d ", abs(a[i]));
  }
  puts("");
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}