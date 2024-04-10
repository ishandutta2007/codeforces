#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
constexpr int kMod = 998244353, kG = 3;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int n, m, l[51], r[51], mu[100001], p[100001], tot, sum[100001], dp[100001];
bool np[100001];
void Init(int n) {
  np[1] = true, mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      np[i * p[j]] = true;
      if (!(i % p[j])) break;
      mu[i * p[j]] = -mu[i];
    }
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(100000);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> l[i] >> r[i];
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (!mu[i]) continue;
    int t = m / i;
    bool flag = false;
    for (int j = 1; j <= n; j++) {
      int tl = (l[j] + i - 1) / i, tr = r[j] / i;
      if (tl < 1) tl = 1;
      if (tr == 0 || tl > tr) {
        flag = true;
        break;
      }
      if (j == 1) {
        std::memset(sum + 1, 0, 4 * t);
        for (int k = tl; k <= tr; k++) sum[k] = 1;
        for (int k = 2; k <= t; k++) Add(sum[k], sum[k - 1]);
        continue;
      }
      for (int k = 1; k <= t; k++)
        dp[k] = sum[std::max(0, k - tl)] - sum[std::max(0, k - tr - 1)];
      std::memset(sum + 1, 0, 4 * t);
      for (int k = 1; k <= t; k++) sum[k] = add(sum[k - 1], dp[k]);
    }
    if (flag) continue;
    int s = 0;
    for (int j = 0; j <= t; j++) Add(s, dp[j]);
    Add(ans, mul(mu[i], s), kMod);
  }
  std::cout << ans;
  return 0;
}