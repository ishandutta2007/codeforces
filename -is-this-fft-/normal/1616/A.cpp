#include <iostream>
#include <map>

using namespace std;

void solve () {
  int n;
  cin >> n;

  map<int, int> cnt;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x < 0) {
      x *= -1;
    }
    
    if (cnt[x] == 2 || (x == 0 && cnt[x] == 1)) {
      continue;
    }

    cnt[x]++;
    ans++;
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