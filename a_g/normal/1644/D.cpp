#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  if (a == 0) return 0;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<pair<int, int>> ops(q);
    for (int j = 0; j < q; j++) {
      cin >> ops[j].first >> ops[j].second;
    }
    set<int> deadrows;
    set<int> deadcols;
    int groups = 0;
    for (int j = q-1; j >= 0; j--) {
      int x = ops[j].first;
      int y = ops[j].second;
      if ((!deadrows.count(x) && deadcols.size() < m) ||
          (!deadcols.count(y) && deadrows.size() < n)) {
        groups++;
      }
      deadrows.insert(x);
      deadcols.insert(y);
    }

    cout << expmod(k, groups, MOD) << '\n';
  }
}