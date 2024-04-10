#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9;

struct event {
  int x;
  int y;
  int t;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int r, n;
  cin >> r >> n;
  vector<int> dp(n+1, -INF);
  vector<int> dpmax(n+1);
  dp[0] = 0;
  vector<event> c(n+1);
  c[0] = {1, 1, 0};
  for (int i = 1; i <= n; i++) {
    cin >> c[i].t >> c[i].x >> c[i].y;
    int j = i-1;
    for (; j >= 0 && c[j].t >= c[i].t - N; j--) {
      if (abs(c[i].x - c[j].x) + abs(c[i].y - c[j].y) <= c[i].t - c[j].t) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    if (j >= 0) dp[i] = max(dp[i], dpmax[j]+1);
    dpmax[i] = max(dpmax[i-1], dp[i]);
  }
  /*
  for (int i = 0; i <= n; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
  */
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}