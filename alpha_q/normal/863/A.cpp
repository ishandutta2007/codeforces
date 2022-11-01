#include <bits/stdc++.h>

using namespace std;

int x;

bool pal (string s) {
  int l = s.size();
  for (int i = 0, j = l - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) return 0;
  }
  return 1;
}

int main() {
  cin >> x;
  string s = "";
  while (x) {
    s += char('0' + x % 10);
    x /= 10;
  }
  for (int i = 0; i < 10; ++i) {
    if (pal(s)) {
      puts("YES");
      return 0;
    }
    s += '0';
  }
  puts("NO");
  return 0;
}