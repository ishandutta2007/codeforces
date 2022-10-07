#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;
  int n = s.size();
  std::vector<int> sta;
  sta.push_back(n);
  std::vector<int> nxt(n + 1);
  nxt[n] = n;

  auto cmp = [&](int i, int j) {
    while (i < n && j < n && s[i] == s[j]) {
      i = nxt[i + 1];
      j = nxt[j + 1];
    }
    if (i < n && j < n) {
      return s[i] < s[j];
    } else {
      return j < n;
    }
  };

  for (int i = n - 1; i >= 0; --i) {
    nxt[i] = i;
    if (s[i] == ')') {
      sta.push_back(i);
    } else {
      sta.pop_back();
      if (sta.empty()) {
        sta.push_back(i);
      } else if (cmp(i, sta.back())) {
        sta.back() = i;
      } else {
        nxt[i] = sta.back();
      }
    }
  }
  for (int i = 0; i < n; i = nxt[i + 1]) {
    std::cout << s[i];
  }
  std::cout << "\n";
}