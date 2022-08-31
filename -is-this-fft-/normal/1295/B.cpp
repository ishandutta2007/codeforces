#include <iostream>
#include <string>

using namespace std;

void solve () {
  int n, k;
  cin >> n >> k;

  string str;
  cin >> str;

  int tot = 0;
  for (char c : str) {
    if (c == '0') tot++;
    else tot--;
  }

  int ans = 0;
  int cur = 0;
  for (char c : str) {
    if (tot == 0 && cur == k) {
      cout << -1 << '\n';
      return;
    }
    
    if (tot != 0) {
      if ((k - cur) % tot == 0 && (k - cur) / tot >= 0) {
        ans++;
      }
    }
    
    if (c == '0') cur++;
    else cur--;
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}