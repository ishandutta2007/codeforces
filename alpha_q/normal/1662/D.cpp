#include <bits/stdc++.h>

using namespace std;

vector <char> get (string S) {
  vector <char> ret;
  bool B = 0;
  for (char c : S) {
    if (c == 'B') {
      B ^= 1;
      continue;
    }
    if (ret.empty() or c != ret.back()) {
      ret.emplace_back(c);
      continue;
    }
    ret.pop_back();
  }
  if (B) ret.emplace_back('B');
  return ret;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string P, Q;
    cin >> P >> Q;
    puts(get(P) == get(Q) ? "YES" : "NO");
  }
  return 0;
}