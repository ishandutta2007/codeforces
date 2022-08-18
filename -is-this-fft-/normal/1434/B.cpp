#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

class Fenwick {
  int n;
  vector<int> tree;
public:
  Fenwick (int _n) : n(_n), tree(n, 0) {}

  void upd (int pos, int val) {
    pos = n - pos;
    for (int i = pos; i < n; i += i & -i) {
      tree[i] = max(tree[i], val);
    }
  }

  int get (int pos) {
    pos = n - pos;
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      ans = max(ans, tree[i]);
    }
    return ans;
  }
};

vector<pair<int, int>> events [MAX_N];
  
int main () {
  int n;
  cin >> n;

  Fenwick fen (MAX_N);
  int cur = 0;
  for (int i = 0; i < 2 * n; i++) {
    char c;
    cin >> c;

    if (c == '+') {
      cur++;
    } else {
      int val;
      cin >> val;

      int l = fen.get(val) + 1;
      int r = cur;
      fen.upd(val, cur);

      if (l > r) {
        failure();
      }

      events[l].push_back(make_pair(r, val));
    }
  }

  set<pair<int, int>> Q;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (auto pr : events[i]) {
      Q.insert(pr);
    }

    if (Q.empty()) {
      failure();
    }

    auto pr = *Q.begin();
    if (pr.first < i) {
      failure();
    }

    Q.erase(pr);
    ans.push_back(pr.second);
  }

  cout << "YES" << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}