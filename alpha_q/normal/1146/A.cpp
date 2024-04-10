#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  int a = 0, n = s.size();
  for (int i = 0; i < n; ++i) {
    a += s[i] == 'a';
  }
  int oth = n - a;
  if (a > oth) {
    cout << n << endl;
  } else {
    cout << a + a - 1 << endl;
  }
  return 0;
}