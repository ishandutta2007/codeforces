#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> cnt(n, vector<int>(2, 0));
    for (int i = 0; i < l; i++) {
      int x;
      cin >> x;
      x--;
      cnt[x][0]++;
    }
    for (int i = 0; i < r; i++) {
      int x;
      cin >> x;
      x--;
      cnt[x][1]++;
    }
    for (int i = 0; i < n; i++) {
      int foo = min(cnt[i][0], cnt[i][1]);
      cnt[i][0] -= foo;
      cnt[i][1] -= foo;
    }
    vector<int> sum(2, 0);
    for (int i = 0; i < n; i++) {
      sum[0] += cnt[i][0];
      sum[1] += cnt[i][1];
    }
    if (sum[0] > sum[1]) {
      swap(sum[0], sum[1]);
      for (int i = 0; i < n; i++) swap(cnt[i][0], cnt[i][1]);
    }
    int need = sum[1] - sum[0];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (cnt[i][1] >= 2 && need > 0) {
        cnt[i][1] -= 2;
        need -= 2;
        ans++;
      }
    }
    ans += sum[0];
    ans += need;
    cout << ans << '\n';
  }

  return 0;
}