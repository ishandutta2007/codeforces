#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

const int MAX_N = 1005;

char ans [MAX_N][MAX_N];
deque<char> lets;

int target, wordl;
void solve_grp (int l, int r, int t) {
  if (t >= wordl) return;
  
  if (l <= target && target <= r) {
    for (int i = l; i <= target; i++) {
      ans[i][t] = lets.front();
      lets.pop_front();
    }
    for (int i = r; i > target; i--) {
      ans[i][t] = lets.back();

      lets.pop_back();
    }

    int bk = l;
    for (int i = l + 1; i <= r; i++) {
      if (ans[i][t] != ans[i - 1][t]) {
        solve_grp(bk, i - 1, t + 1);
        bk = i;
      }
    }
    solve_grp(bk, r, t + 1);
  } else {
    for (int i = r; i >= l; i--) {
      ans[i][t] = lets.back();
      lets.pop_back();
    }

    solve_grp(l, r, t + 1);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int wordc;
  cin >> wordc >> wordl >> target;
  target--;

  string str;
  cin >> str;
  for (char c : str) {
    lets.push_back(c);
  }

  sort(lets.begin(), lets.end());

  solve_grp(0, wordc - 1, 0);
  for (int i = 0; i < wordc; i++) {
    for (int j = 0; j < wordl; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
}