#include <bits/stdc++.h>
using namespace std;

const bool testing = 0;
int t[9] = {0, 3, 2, 0, 3, 0, 5, 5, 5};

int query(int i, int j, int k) {
  cout << "? " << i << " " << j << " " << k << endl;
  if (testing) {
    return max({t[i], t[j], t[k]}) - min({t[i], t[j], t[k]});
  }
  int ans;
  cin >> ans;
  if (ans == -1) exit(0);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int diff = -1;
    int v = 0;
    bool all_equal = 1;
    for (int i = 3; i <= n; i++) {
      int x = query(1, 2, i);
      if (v && x != diff) all_equal = 0;
      if (x > diff) {
        diff = x;
        v = i;
      }
    }

    bool flag1 = 0;
    bool flag2 = 0;
    if (all_equal) {
      assert(v == 3);
      int x = query(2, 3, 4);
      int y = query(1, 3, 4);
      if (x > diff || y > diff) {
        assert(x == y);
      }
      else if (x == diff && y == diff) {
        ;
      }
      else if (x < diff && y < diff) {
        cout << "! 1 2" << endl;
        continue;
      }
      else {
        flag1 = 1;
        flag2 = (x > y);
      }
    }
    
    int diff2 = -1;
    int w = 0;
    bool all_equal2 = 1;
    for (int i = 2; i <= n; i++) {
      if (i == v) continue;
      int x = query(1, i, v);
      if (w && x != diff2) all_equal2 = 0;
      if (x > diff2) {
        diff2 = x;
        w = i;
      }
    }

    if (!flag1) {
      if (all_equal2) {
        cout << "! 1 " << v << endl;
        continue;
      }
      cout << "! " << w << " " << v << endl;
      continue;
    }

    assert(diff2 >= diff);
    if (diff2 > diff) {
      cout << "! " << w << " " << v << endl;
      continue;
    }

    cout << "! 1 2" << endl;
  }
}