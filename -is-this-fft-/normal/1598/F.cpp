#include <iostream>
#include <vector>

using namespace std;

struct Summary {
  int bal;
  vector<int> seen; // negative indices
  vector<int> cnt; // again negative indices

  pair<int, bool> count (int val) { // true if it breaks
    val *= -1;
    if (val + 1 >= (int) seen.size()) {
      return {0, 0};
    }
    return {cnt[val], seen[val + 1]};
  }
};

Summary summarize (const string &s) {
  Summary sum;
  sum.seen = vector<int> ((int) s.size() + 5, 0);
  sum.cnt = vector<int> ((int) s.size() + 5, 0);

  int bal = 0;
  for (char c : s) {
    if (c == '(') {
      bal++;
    } else {
      bal--;
    }

    if (bal <= 0) {
      if (!sum.seen[-bal + 1]) {
        sum.cnt[-bal]++;
      }
      sum.seen[-bal]++;
    }
  }

  sum.bal = bal;
  return sum;
}

const int MAX_N = 20;
const int INF = 1e9 + 5;

Summary arr [MAX_N];
int dp [1 << MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    arr[i] = summarize(s);
  }

  for (int i = 0; i < 1 << n; i++) {
    dp[i] = -INF;
  }

  int ans = 0;
  dp[0] = 0;
  for (int mask = 0; mask < 1 << n; mask++) {
    if (dp[mask] < 0) continue;
    ans = max(ans, dp[mask]);
    
    int bal = 0;
    for (int i = 0; i < n; i++) {
      if (mask & 1 << i) {
        bal += arr[i].bal;
      }
    }

    if (bal < 0) continue;
    
    for (int i = 0; i < n; i++) {
      if (!(mask & 1 << i)) {
        auto pr = arr[i].count(-bal);
        if (pr.second) {
          ans = max(ans, dp[mask] + pr.first);
        } else {
          dp[mask | 1 << i] = max(dp[mask | 1 << i], dp[mask] + pr.first);
        }
      }
    }
  }

  cout << ans << '\n';
}