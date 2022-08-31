#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    if (s.size() > 10) {
      cout << s[0] << (int) s.size() - 2 << s.back() << endl;
    } else {
      cout << s << endl;
    }
  }
}