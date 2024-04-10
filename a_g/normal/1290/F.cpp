#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct state {
  int sx, sy, mx, my;
};

bool operator < (const state& lhs, const state& rhs) {
  return make_tuple(lhs.sx, lhs.sy, lhs.mx, lhs.my) <
    make_tuple(rhs.sx, rhs.sy, rhs.mx, rhs.my);
}

state emp{0, 0, 0, 0};

const int B = 32;
map<state, int> dp[B];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (auto& p: v) {
    cin >> p.first >> p.second;
  }

  dp[0][emp] = 1;
  for (int i = 0; i < B-1; i++) {
    for (auto& [s, x]: dp[i]) {
      for (int mask = 0; mask < (1<<n); mask++) {
        state ns = s;
        for (int j = 0; j < n; j++) {
          if ((mask>>j)&1) {
            ns.sx += v[j].first;
            ns.sy += v[j].second;
            ns.mx += max(0, v[j].first);
            ns.my += max(0, v[j].second);
          }
        }
        if ((ns.sx&1) || (ns.sy&1)) continue;
        if (!((m>>i)&1)) {
          if (ns.mx&1) ns.mx++;
          if (ns.my&1) ns.my++;
        }
        ns.sx /= 2;
        ns.sy /= 2;
        ns.mx /= 2;
        ns.my /= 2;
        add(dp[i+1][ns], x);
      }
    }
  }
  int ans = dp[B-1][emp]-1;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}