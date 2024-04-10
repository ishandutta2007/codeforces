#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e6 + 5;
const int MAX_K = 1e5 + 5;

bool in_off [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;

  vector<int> ans;
  int cur_p = 0;
  int last = -1;
  set<int> entrs;
  for (int i = 0; i < length; i++) {
    int ev;
    cin >> ev;

    if (ev < 0) {
      if (in_off[-ev]) {
        cur_p--;
        in_off[-ev] = 0;
      } else {
        cout << -1 << endl;
        return 0;
      }
    } else {
      if (in_off[ev]) {
        cout << -1 << endl;
        return 0;
      } else {
        if (entrs.count(ev) != 0) {
          cout << -1 << endl;
          return 0;
        }
        cur_p++;
        in_off[ev] = 1;
        entrs.insert(ev);
      }
    }

    if (cur_p == 0) {
      entrs.clear();
      ans.push_back(i - last);
      last = i;
    }
  }

  if (cur_p != 0) {
    cout << -1 << endl;
    return 0;
  }

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}