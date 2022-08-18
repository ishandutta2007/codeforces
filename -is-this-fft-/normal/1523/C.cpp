#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> stk;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x == 1) {
      stk.push_back(x);
    } else {
      while (stk.back() != x - 1) {
        stk.pop_back();
      }
      stk.back()++;
    }

    for (int j = 0; j < (int) stk.size(); j++) {
      if (j != 0) cout << '.';
      cout << stk[j];
    }
    cout << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}