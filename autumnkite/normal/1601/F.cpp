#include <bits/stdc++.h>

constexpr int P1 = 998244353, P2 = 1000000007;

long long n;

std::vector<int> val[7];
long long sum[7];

void dfs1(int k, int v) {
  static int idx = 0;
  val[k].push_back((idx + P1 - v) % P1);
  ++idx;
  if (k == 6) {
    return;
  }
  for (int i = 0; i <= 9; ++i) {
    dfs1(k + 1, v * 10 + i);
  }
}

int ans;

void dfs2(int k, long long v) {
  if (v > n) {
    return;
  }
  static long long idx = 1;
  if (v * 10000000 > n && (v + 1) * 1000000 - 1 <= n) {
    int pw = 1;
    for (int i = 0; i <= 6; ++i) {
      int tmp = (idx + P1 - v * pw % P1) % P1;
      int c = val[i].size();
      int p = std::lower_bound(val[i].begin(), val[i].end(), P1 - tmp)
              - val[i].begin();
      ans = (ans + 1ll * tmp * c + sum[i] - 1ll * (c - p) * P1) % P2;
      pw *= 10;
    }
    for (int i = 0; i <= 6; ++i) {
      idx += val[i].size();
    }
    return;
  }
  ans = (ans + (idx + P1 - v % P1) % P1) % P2;
  ++idx;
  for (int i = 0; i <= 9; ++i) {
    dfs2(k + 1, v * 10 + i);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  dfs1(0, 0);
  for (int i = 0; i <= 6; ++i) {
    std::sort(val[i].begin(), val[i].end());
    sum[i] = std::accumulate(val[i].begin(), val[i].end(), 0ll);
  }
  for (int i = 1; i <= 9; ++i) {
    dfs2(1, i);
  }
  std::cout << ans << "\n";
}