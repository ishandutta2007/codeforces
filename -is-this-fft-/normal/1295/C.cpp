#include <iostream>
#include <set>

using namespace std;

set<int> nxt [200];

void solve () {
  for (int i = 'a'; i <= 'z'; i++) {
    nxt[i].clear();
  }
  
  string s, t;
  cin >> s >> t;

  for (int i = 0; i < (int) s.size(); i++) {
    nxt[s[i]].insert(i);
  }

  int cur_ptr = -1;
  int ans = 1;
  for (char c : t) {
    if (nxt[c].upper_bound(cur_ptr) == nxt[c].end()) {
      cur_ptr = -1;
      ans++;
      
      if (nxt[c].upper_bound(cur_ptr) == nxt[c].end()) {
        cout << -1 << '\n';
        return;
      }
    }

    cur_ptr = *nxt[c].upper_bound(cur_ptr);
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