#include <bits/stdc++.h>

const int N = 128;

int dp[N];

int calc(int x) {
  if (dp[x] != -1) {
    return dp[x];
  }
  if (x == 0 || x == 1) {
    return 0;
  }
  if (x == 2 || x == 3) {
    return 1;
  }
  std::vector<bool> vis(N);
  for (int i = 0; i <= x - 2; ++i) {
    vis[calc(i) ^ calc(x - i - 2)] = true;
  }
  dp[x] = 0;
  while (vis[dp[x]]) {
    ++dp[x];
  }
  return dp[x];
}

int SG(int x) {
  if (x < N) {
    return calc(x);
  }
  return SG(x % 34 + 2 * 34);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::fill(dp, dp + N, -1);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int A = 0, B = 0;
    for (char c : s) {
      if (c == 'R') {
        ++A;
      } else {
        ++B;
      }
    }
    if (A > B) {
      std::cout << "Alice\n";
      continue;
    }
    if (A < B) {
      std::cout << "Bob\n";
      continue;
    }
    int ans = 0, len = 1;
    for (int i = 0; i < n; ++i) {
      if (i + 1 == n || s[i] == s[i + 1]) {
        ans ^= SG(len);
        len = 1;
      } else {
        ++len;
      }
    }
    std::cout << (ans ? "Alice" : "Bob") << "\n";
  }
}