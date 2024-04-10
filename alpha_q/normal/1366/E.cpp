#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

int n, m, a[N], b[N];
map <int, vector <int>> pos;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    pos[a[i]].emplace_back(i);
  }
  int last = -1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", b + i);
    if (pos.find(b[i]) == pos.end()) {
      puts("0");
      return 0;
    }
    if (last != -1 and pos[b[i]].back() < last) {
      puts("0");
      return 0;
    }
    last = pos[b[i]].back();
  }
  for (int i = 1; i <= pos[b[1]].back(); ++i) {
    if (a[i] < b[1]) {
      puts("0");
      return 0;
    }
  }
  for (int i = pos[b[m]].back(); i <= n; ++i) {
    if (a[i] < b[m]) {
      puts("0");
      return 0;
    }
  }
  int ans = 1;
  for (int i = 1; i < m; ++i) {
    int x = b[i], y = b[i + 1], st = pos[x].back();
    for (int j = pos[x].back(); j < pos[y].back(); ++j) {
      if (a[j] < x) {
        puts("0");
        return 0;
      }
      if (a[j] < y) st = j;
    }
    ans = (long long) ans * (pos[y].back() - st) % MOD;
  }
  cout << ans << '\n';
  return 0;
}