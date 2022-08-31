#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;

int f[maxN], siz[maxN];
int n, m;

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) f[i] = i;
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (find(u) == find(v)) ++cnt;
    else f[find(u)] = find(v);
    memset(siz, 0, sizeof(siz));
    for (int j = 1; j <= n; j++) ++siz[find(j)];
    sort(siz + 1, siz + n + 1);
    int ans = 0;
    for (int j = n; j >= n - cnt; j--) ans += siz[j];
    printf("%d\n", ans - 1);
  }
  return 0;
}