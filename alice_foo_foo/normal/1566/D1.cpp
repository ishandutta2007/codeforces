#include <bits/stdc++.h>
using namespace std;

const int maxN = 305;

vector <int> vec[maxN * maxN];
int a[maxN * maxN], b[maxN * maxN], used[maxN][maxN], cnt[maxN * maxN];
int T, n, m, ans;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]), b[i] = a[i], vec[i].clear(), cnt[i] = 0;
    sort(b + 1, b + n * m + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i * m; j >= (i - 1) * m + 1; j--) {
        int id = lower_bound(b + 1, b + n * m + 1, b[j]) - b;
        vec[id].push_back(j);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        used[i][j] = 0;
      }
    }
    ans = 0;
    for (int i = 1; i <= n * m; i++) {
      int id = lower_bound(b + 1, b + n * m + 1, a[i]) - b;
      int pos = vec[id][cnt[id]]; ++cnt[id];
      int x = (pos - 1) / m + 1, y = pos - (x - 1) * m;
      for (int j = 1; j <= y; j++) ans += used[x][j];
      used[x][y] = 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}