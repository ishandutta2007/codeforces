#include <bits/stdc++.h>

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  std::vector<std::array<int, 2>> cnt(2 * n + 1);
  int now = n;
  for (int i = 0; i < n; ++i) {
    ++cnt[now][s[i] - '0'];
    if (s[i] == '0') {
      --now;
    } else {
      ++now;
    }
  }
  now = n;
  for (int i = 0; i < n; ++i) {
    if (cnt[now][0] && cnt[now - 1][1]) {
      --cnt[now][0];
      --now;
      std::cout << '0';
    } else if (cnt[now][1]) {
      --cnt[now][1];
      ++now;
      std::cout << '1';
    } else {
      --cnt[now][0];
      --now;
      std::cout << '0';
    }
  }
  std::cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}