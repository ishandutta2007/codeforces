#include <iostream>
#include <vector>

using namespace std;

struct State {
  int cur, oth, lb;

  State (int _cur = 0, int _oth = 0, int _lb = 0) :
    cur(_cur), oth(_oth), lb(_lb) {}
};

const int MAX_N = 105;
const int ALPH = 30;

int _vis [MAX_N][MAX_N][ALPH];
int _dp [MAX_N][MAX_N][ALPH];

vector<pair<int, int>> adj [MAX_N]; // <nxt, char>

int& vis (State s) {
  return _vis[s.cur][s.oth][s.lb];
}

int& dp (State s) {
  return _dp[s.cur][s.oth][s.lb];
}

int calc_dp (State s) {
  if (vis(s)) return dp(s);

  int ans = 0;
  for (auto nxt : adj[s.cur]) {
    if (nxt.second >= s.lb) {
      ans |= !calc_dp(State(s.oth, nxt.first, nxt.second));
    }
  }

  vis(s) = 1;
  dp(s) = ans;
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;

    adj[u].push_back(make_pair(v, c - 'a'));
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (calc_dp(State(i, j, 0)) ? 'A' : 'B');
    }
    cout << '\n';
  }
}