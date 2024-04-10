#include <iostream>

using namespace std;

const int INF = 1e9 + 5;

int solve (const string &s, const string &t, bool inv) {
  int n01 = 0, n10 = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '0' && t[i] == '1') {
      n01++;
    } else if (s[i] == '1' && t[i] == '0') {
      n10++;
    }
  }

  if (inv) {
    if (n10 == 1 + n01) {
      return n10 + n01;
    } else {
      return INF;
    }
  } else {
    if (n10 == n01) {
      return n10 + n01;
    } else {
      return INF;
    }
  }
}

void solve () {
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  int ans = solve(s, t, false);
  for (int i = 0; i < n; i++) {
    if (t[i] == '0') t[i] = '1';
    else t[i] = '0';
  }
  ans = min(ans, solve(s, t, true));

  if (ans == INF) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
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