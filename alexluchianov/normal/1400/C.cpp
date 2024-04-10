#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

std::string _transform(std::string s, int w) {
  std::string s2;
  s2.resize(s.size());

  for(int i = 0; i < s.size(); i++) {
    if(0 <= i - w && i + w < s.size())
      s2[i] = std::min(s[i - w], s[i + w]);
    else if(0 <= i - w)
      s2[i] = s[i - w];
    else if(i + w < s.size())
      s2[i] = s[i + w];
    else
      s2[i] = '0';
  }
  return s2;
}

std::string _transform2(std::string s, int w) {
  std::string s2;

  s2.resize(s.size());
  for(int i = 0; i < s.size(); i++) {
    if(0 <= i - w && i + w < s.size())
      s2[i] = std::max(s[i - w], s[i + w]);
    else if(0 <= i - w)
      s2[i] = s[i - w];
    else if(i + w < s.size())
      s2[i] = s[i + w];
    else
      s2[i] = '0';
  }
  return s2;
}

void solve() {
  std::string s;
  int w;
  std::cin >> s >> w;
  std::string s2 = _transform(s, w);
  if(s == _transform2(s2, w))
    std::cout << s2 << '\n';
  else
    std::cout << -1 << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}