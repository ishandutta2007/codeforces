#include <bits/stdc++.h>

void solve() {
  std::string s;
  std::cin >> s;
  std::vector<int> pos(26);
  for (int i = 0; i < 26; ++i) {
    pos[s[i] - 'a'] = i;
  }
  std::cin >> s;
  int ans = 0;
  for (int i = 0; i < (int)s.size() - 1; ++i) {
    ans += abs(pos[s[i] - 'a'] - pos[s[i + 1] - 'a']);
  }
  std::cout << ans << "\n";
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