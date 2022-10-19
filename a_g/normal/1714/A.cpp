#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, h, m;
    cin >> n >> h >> m;
    int t = 60*h+m;
    set<int> s;
    while (n--) {
      int x, y;
      cin >> x >> y;
      s.insert(60*x+y);
    }
    int ans = 0;
    while (!s.count(t)) {
      ans++;
      t++;
      if (t == 60*24) t = 0;
    }
    cout << ans/60 << " " << ans%60 << '\n';
  }
}