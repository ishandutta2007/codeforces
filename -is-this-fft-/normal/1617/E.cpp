#include <iostream>
#include <vector>
#include <map>

using namespace std;

int reduce (int x) {
  if (x == 1 << __lg(x)) {
    return 0;
  }
  
  return (1 << (__lg(x) + 1)) - x;
}

const int INF = 1e9 + 5;

struct Sol {
  int nxt, src, ans;

  Sol () : nxt(-2), src(-2), ans(-INF) {}
};

map<int, pair<Sol, Sol>> dp;
pair<int, pair<int, int>> ans;

void explr (int u, int idx) {
  int last = -1, dist = 0;
  for (int cur = u; true; cur = reduce(cur)) {
    Sol match;
    if (last != -1 && dp[cur].first.nxt == last) {
      match = dp[cur].second;
    } else {
      match = dp[cur].first;
    }

    ans = max(ans, make_pair(match.ans + dist, make_pair(idx, match.src)));

    Sol my;
    my.nxt = last;
    my.src = idx;
    my.ans = dist;
    if (my.ans >= dp[cur].first.ans) {
      if (last == -1 || last != dp[cur].first.nxt) {
        dp[cur].second = dp[cur].first;
      }
      dp[cur].first = my;
    } else if (my.ans >= dp[cur].second.ans) {
      if (last == -1 || last != dp[cur].first.nxt) {
        dp[cur].second = my;
      }
    }
    
    dist++;
    last = cur;
    if (cur == 0) {
      break;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    explr(x, i);
  }

  cout << ans.second.first << " " << ans.second.second << " " << ans.first << '\n';
}