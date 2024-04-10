#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 105;
const int MAX_T = 20;

int n;
int arr [MAX_N];

bool _has [MAX_T][1 << MAX_T];
int _dp [MAX_T][1 << MAX_T];

char action [MAX_T];
int team [MAX_T];

int turnc;
int dp (int turn, int mask) {
  if (turn == turnc) {
    return 0;
  }
  
  if (_has[turn][mask]) {
    return _dp[turn][mask];
  }

  // both maximize, if team is 2 then we flip before and after
  _dp[turn][mask] = -INF;
  int sg = team[turn] == 2 ? -1 : 1;
  if (action[turn] == 'p') {
    for (int i = 0; i < n; i++) {
      if (!(mask & 1 << i)) {
        _dp[turn][mask] = max(_dp[turn][mask], arr[i] + sg * dp(turn + 1, mask | 1 << i));
      }
    }
  } else {
    _dp[turn][mask] = max(_dp[turn][mask], sg * dp(turn + 1, mask));
    for (int i = 0; i < n; i++) {
      if (!(mask & 1 << i)) {
        _dp[turn][mask] = max(_dp[turn][mask], sg * dp(turn + 1, mask | 1 << i));
      }
    }
  }

  _dp[turn][mask] *= sg;
  _has[turn][mask] = 1;
  return _dp[turn][mask];
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  reverse(arr, arr + n);

  cin >> turnc;
  for (int i = 0; i < turnc; i++) {
    cin >> action[i] >> team[i];
  }

  n = min(n, turnc);
  cout << dp(0, 0) << endl;
}