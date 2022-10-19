#include <bits/stdc++.h>
using namespace std;

struct pt {
  int x, y;
};

pt operator - (pt& a, pt& b) {
  return pt{a.x-b.x, a.y-b.y};
}

bool operator < (const pt&a, const pt& b) {
  bool aq = (a.y > 0 || a.y == 0 && a.x > 0);
  bool bq = (b.y > 0 || b.y == 0 && b.x > 0);
  if (aq != bq) return aq > bq;
  return 1LL*a.x*b.y > 1LL*b.x*a.y;
}

const int K = 6;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pt> pts(n);
  for (pt& p: pts) cin >> p.x >> p.y;
  vector<tuple<pt, int, int>> segs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      segs.emplace_back(pts[j]-pts[i], i, j);
    }
  }
  vector dp(n, vector<array<int, K>>(n));
  for (int i = 0; i < n; i++) {
    dp[i][i][0] = 1;
    for (int j = 0; j < n; j++) {
      for (int k = 1; k < K; k++) {
        dp[i][j][k] = 0;
      }
    }
  }
  sort(segs.begin(), segs.end());
  for (auto& [_, i, j]: segs) {
    for (int p = 0; p < n; p++) {
      for (int k = 0; k+1 < K; k++) {
        dp[p][j][k+1] += dp[p][i][k];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i][i][K-1];
  }
  cout << ans << '\n';
}