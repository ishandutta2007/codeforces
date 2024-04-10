#include <iostream>
#include <vector>

using namespace std;

class Fenwick {
  vector<int> tree;
 
public:
  Fenwick (int _n) : tree(_n + 1, 0) {
  }
 
  void add (int idx, int val) {
    idx++;
 
    for (int i = idx; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }
 
  int get (int idx) {
    idx++;
 
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
 
  int range (int l, int r) {
    return get(r) - get(l - 1);
  }
};

void solve () {
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  Fenwick rowr (m);
  int gcols = 0;
  vector<int> colr (m, 0);
  int last_good = -1;
  for (int i = 0; i < (int) s.size(); i++) {
    bool is = s[i] == '1';

    if (is) {
      if (last_good == -1) {
        rowr.add(0, 1);
      } else {
        // they become the rep of row 1 when last_good leaves that
        // they stop being the rep of row 1 when they themselves leave that
        int l;
        if (i - last_good >= m) {
          l = i;
        } else {
          l = m + last_good;
        }
        int r = m + i;

        rowr.add(l % m, 1);
        rowr.add(r % m, -1);
        if (l < r && r % m <= l % m) {
          rowr.add(0, 1);
        }
      }

      if (colr[i % m] == 0) {
        colr[i % m] = 1;
        gcols++;
      }
          
      last_good = i;
    }

    int ans = rowr.get(i % m);
    ans += gcols;

    cout << ans << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++)
    solve();
}