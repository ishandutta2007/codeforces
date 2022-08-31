#include <iostream>

using namespace std;

void solve () {
  int n, z;
  cin >> n >> z;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    
    ans = max(ans, x | z);
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