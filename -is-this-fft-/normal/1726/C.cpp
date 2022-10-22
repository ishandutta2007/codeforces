#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;
  n *= 2;
  
  string s;
  cin >> s;

  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '(' && s[i + 1] != ')') {
      ans++;
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}