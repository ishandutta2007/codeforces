#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    string block;
    bool win = 1;
    auto check = [&] () {
      int n = block.size();
      if (n == 0) return;
      if (count(block.begin(), block.end(), 'B') == n || count(block.begin(), block.end(), 'R') == n) {
        win = 0;
      }
      block.clear();
    };
    for (char c: s) {
      if (c == 'W') {
        check();
      }
      else {
        block.push_back(c);
      }
    }
    check();
    cout << (win ? "YES" : "NO") << '\n';
  }
}