#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int ans = 1;
    set<int> mem;
    for (char c: s) {
      if (mem.count(c)) continue;
      else if (mem.size() == 3) {
        ans++;
        mem.clear();
      }
      mem.insert(c);
    }
    cout << ans << '\n';
  }
}