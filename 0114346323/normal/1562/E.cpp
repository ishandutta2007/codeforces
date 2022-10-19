#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, m, p, sa[5005], rk[5005], trk[5005], sum[5005], ht[5005],
    lcp[5005][5005], dp[5005];
char s[5005];
void Sort() {
  for (int i = 1; i <= m; i++) sum[i] = 0;
  for (int i = 1; i <= n; i++) sum[rk[i]]++;
  for (int i = 2; i <= m; i++) sum[i] += sum[i - 1];
  for (int i = n; i >= 1; i--) sa[sum[rk[trk[i]]]--] = trk[i];
}
void get_SA() {
  for (int i = 1; i <= n; i++) {
    rk[i] = s[i];
    sum[rk[i]]++;
    trk[i] = i;
  }
  Sort();
  for (int len = 1; len <= n; len <<= 1) {
    p = 0;
    for (int i = n - len + 1; i <= n; i++) trk[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > len) trk[++p] = sa[i] - len;
    Sort();
    memcpy(trk, rk, sizeof(rk));
    p = rk[sa[1]] = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = trk[sa[i]] == trk[sa[i - 1]] &&
                          trk[sa[i] + len] == trk[sa[i - 1] + len]
                      ? p
                      : ++p;
    if (p == n) break;
    m = p;
  }
}
void get_height() {
  int k = 0;
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  for (int i = 1; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    ht[rk[i]] = k;
  }
}
void Solve() {
  std::cin >> n >> (s + 1), m = 200;
  for (int i = 1; i <= std::max(n, 200); i++)
    sa[i] = rk[i] = trk[i] = sum[i] = ht[i] = 0;
  get_SA(), get_height();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) lcp[i][j] = 0;
  for (int i = 1; i < n; i++) {
    int min = 0x3f3f3f3f;
    for (int j = i + 1; j <= n; j++) {
      checkmin(min, ht[j]);
      lcp[sa[i]][sa[j]] = lcp[sa[j]][sa[i]] = min;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = n - i + 1;
    int max = 0;
    for (int j = 1; j < i; j++) {
      int x = i + lcp[i][j], y = j + lcp[i][j];
      if (x <= n && s[x] > s[y]) checkmax(max, dp[j] - lcp[i][j]);
    }
    dp[i] += max;
  }
  std::cout << *std::max_element(dp + 1, dp + n + 1) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}