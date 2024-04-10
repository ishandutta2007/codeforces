#include <bits/stdc++.h>
using namespace std;
const int N = 1020;
int n, r[N], c[N], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &r[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = n; i; i--) {
    if (r[i] == i && c[i] == i) continue;
    ans++;
    for (int j = 1; j <= i; j++) if (r[j] == i) r[j] = r[i];
    for (int j = 1; j <= i; j++) if (c[j] == i) c[j] = c[i];
  }
  printf("%d\n", ans);
  for (int i = n; i; i--) {
    if (r[i] == i && c[i] == i) continue;
    printf("%d %d %d %d\n", r[i], i, i, c[i]);
  }
}