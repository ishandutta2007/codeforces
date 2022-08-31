#include <iostream>

using namespace std;

const int INF = 1e9 + 5;

struct TwoBest {
  pair<int, int> best; // <value, index>
  pair<int, int> sbest;

public:
  TwoBest () {
    best = make_pair(0, 0);
    sbest = make_pair(-INF, -1);
  }
  
  void add_to_all (int val) {
    best.first += val;
    sbest.first += val;
  }

  int max_except (int idx) {
    if (idx == best.second) {
      return sbest.first;
    }
    return best.first;
  }

  void upd (int idx, int val) {
    if (idx == best.second) {
      best.first = max(best.first, val);
      return;
    }

    if (idx == sbest.second) {
      sbest.first = max(sbest.first, val);
      if (sbest > best) {
        swap(best, sbest);
      }
      return;
    }

    auto pr = make_pair(val, idx);
    if (pr > best) {
      sbest = best;
      best = pr;
      return;
    }

    if (pr > sbest) {
      sbest = pr;
    }
  }
};

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int last = -2;
  TwoBest tb;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int curl = tb.max_except(x) + 1;
    curl = max(curl, tb.best.first);
    if (x != last) {
      tb.add_to_all(1);
    }
    tb.upd(last, curl);

    last = x;
  }

  cout << tb.best.first << endl;
}