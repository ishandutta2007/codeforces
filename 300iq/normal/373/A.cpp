#include <bits/stdc++.h>

using namespace std;

int main() {
  int t[255];
  memset(t, 0, sizeof t);
  int n;
  int ans = 0;
  char c;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> c;
      if (c != '.') ans = max(ans, ++t[c]);
    }
  }
  cout << (ans <= 2 * n ? "YES" : "NO") << endl;
}