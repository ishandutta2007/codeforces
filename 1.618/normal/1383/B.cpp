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

int n, a[maxn];
void solve() {
  int sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum ^= a[i];
  }
  if (!sum) {
    puts("DRAW");
    return;
  }
  int cnt0 = 0, cnt1 = 0, w = 31 - __builtin_clz(sum);
  for (int i = 1; i <= n; i++) {
    if (a[i] & (1 << w)) cnt1++;
    else cnt0++;
  }
  if (cnt1 % 4 == 3 && cnt0 % 2 == 0) {
    puts("LOSE");
    return;
  }
  puts("WIN");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}