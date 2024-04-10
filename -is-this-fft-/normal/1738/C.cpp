#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;

bool memo [MAX_N][MAX_N][2][2];

// is this state winning for the current player?
int dp [MAX_N][MAX_N][2][2]; // # of 0, # of 1, sum of alice, player (0 = alice)

bool calc_dp (int ev, int od, int al, int pl) {
  if (memo[ev][od][al][pl]) {
    return dp[ev][od][al][pl];
  }

  bool ans = false;
  if (ev == 0 && od == 0) {
    ans = al == pl;
  } else {
    if (ev != 0 && !calc_dp(ev - 1, od, al, !pl)) {
      ans = true;
    }

    if (od != 0 && !calc_dp(ev, od - 1, al ^ !pl, !pl)) {
      ans = true;
    }
  }

  dp[ev][od][al][pl] = ans;
  memo[ev][od][al][pl] = 1;

  return ans;
}

void solve () {
  int n;
  cin >> n;

  int ev = 0, od = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x % 2 == 0) {
      ev++;
    } else {
      od++;
    }
  }

  if (calc_dp(ev, od, 0, 0)) {
    cout << "Alice" << '\n';
  } else {
    cout << "Bob" << '\n';
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