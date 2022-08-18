#include <iostream>
#include <algorithm>

using namespace std;

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  string t = s;
  sort(t.begin(), t.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] != s[i]) {
      ans++;
    }
  }

  cout << ans << endl;
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