#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> transform (const map<int, int> &vec) {
  map<int, int> ans;
  for (auto it = vec.begin(); it != vec.end(); it++) {
    if (it->second > 1) {
      ans[0] += it->second - 1;
    }
    auto nxt = next(it);
    if (nxt != vec.end()) {
      ans[nxt->first - it->first] += 1;
    }
  }

  return ans;
}

void solve () {
  int n;
  cin >> n;

  map<int, int> cur;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cur[x]++;
  }

  while (true) {
    if (cur.size() == 1) {
      if (cur.begin()->second == 1) {
        cout << cur.begin()->first << '\n';
      } else {
        cout << 0 << '\n';
      }
      return;
    }

    if (cur.size() == 2 && cur.begin()->first == 0) {
      cout << next(cur.begin())->first << '\n';
      return;
    }
    
    cur = transform(cur);
  }
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