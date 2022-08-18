#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 1e5 + 5;

class TwoBest {
  int gb_add;
  vector<int> value;
  set<pair<int, int>> st; // value, index
  
public:
  TwoBest (int n) {
    gb_add = 0;

    value = vector<int> (n + 5, INF);
    value[0] = 0;

    for (int i = 0; i < (int) value.size(); i++) {
      st.insert(make_pair(value[i], i));
    }
  }
  
  void add_to_all (int val) {
    gb_add += val;
  }

  int min_except (int idx) {
    auto it = st.begin();
    if (st.begin()->second == idx) {
      it = next(st.begin());
    }
    return it->first + gb_add;
  }

  int at (int idx) {
    return value[idx] + gb_add;
  }
  
  void upd (int idx, int val) {
    val -= gb_add;

    st.erase(make_pair(value[idx], idx));
    value[idx] = val;
    st.insert(make_pair(value[idx], idx));
  }
};

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int last = n + 3;
  TwoBest tb (n + 5);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    int curl = min(tb.min_except(x) + 1, tb.at(x));
    if (x != last) {
      tb.add_to_all(1);
    }
    tb.upd(last, curl);

    last = x;
  }

  cout << tb.min_except(n + 1) << endl;
}