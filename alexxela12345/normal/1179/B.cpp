#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  pair<int, int> cur1 = {1, 1}, cur2 = {n, m};
  int cur = 1;
  while (cnt < n * m) {
    cnt++;
    if (cur == 1) {
      cout << cur1.first << " " << cur1.second << endl;
      cur1.second++;
      if (cur1.second == m + 1) {
        cur1.first++;
        cur1.second = 1;
      }
    } else {
      cout << cur2.first << " " << cur2.second << endl;
      cur2.second--;
      if (cur2.second == 0) {
        cur2.first--;
        cur2.second = m;
      }
    }
    cur = 3 - cur;
  }
}