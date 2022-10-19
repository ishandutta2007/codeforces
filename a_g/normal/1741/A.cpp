#include <bits/stdc++.h>
using namespace std;

int f(char c) {
  if (c == 'S') return -1;
  else if (c == 'M') return 0;
  else if (c == 'L') return 1;
  else return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    if (f(s.back()) != f(t.back())) {
      cout << (f(s.back()) < f(t.back()) ? '<' : '>') << '\n';
      continue;
    }
    if (s == t) {
      cout << "=\n";
      continue;
    }
    cout << ((s.back()=='S')^(s.size() > t.size()) ? '>' : '<') << '\n';
  }
}