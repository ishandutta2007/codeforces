#include <iostream>
#include <string>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int has = 0, ans = 0;
  for (char c : s) {
    if (c == '>') {
      has |= 1 << 0;
    } else if (c == '<') {
      has |= 1 << 1;
    } else {
      ans += 2;
    }
  }

  if (has != 3) {
    cout << n << '\n';
    return;
  }

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '-' && s[i + 1] == '-') {
      ans--;
    }
  }
  if (s[0] == '-' && s[n - 1] == '-') {
    ans--;
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  
  for (int t = 0; t < testc; t++) {
    solve();
  }
}