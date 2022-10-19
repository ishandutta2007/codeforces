#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9+100;
pair<int, int> dp[N];
int a[N];
int b[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int l, n;
  cin >> l >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  a[n] = l;
  function<bool(int, int)> check = [&] (int x, int y) {
    // is it possible to make each segment length in [x, y]?
    if (x > y) return 0;
    //cout << '\n';
    //cout << x << " " << y << endl;
    dp[0] = {0, 0};
    for (int i = 0; i < n; i++) {
      if (a[i] > dp[i].second + y || a[i] < dp[i].first) return 0;
      dp[i+1] = make_pair(max(a[i], dp[i].first+x), min(dp[i].second+y, a[i+1]));
      //cout << dp[i+1].first << " " << dp[i+1].second << endl;
    }
    if (l > dp[n].second || l < dp[n].first) return 0;
    return 1;
  };
  int low = 0;
  int high = INF;
  while (high - low > 1) {
    int mid = (low+high)/2;
    if (check(mid, INF)) low = mid;
    else high = mid;
  }

  int low2 = 0;
  int high2 = INF;
  while (high2 - low2 > 1) {
    int mid = (low2+high2)/2;
    if (check(low, mid)) high2 = mid;
    else low2 = mid;
  }
  //cout << low << " " << high2 << endl;
  check(low, high2);
  b[n] = l;
  for (int i = n-1; i >= 0; i--) {
    //cout << dp[i].first << " " << dp[i].second << " " << b[i+1] << '\n';
    for (int u: {dp[i].first, dp[i].second, b[i+1]-low, b[i+1]-high2}) {
      //cout << i << " " << a[i] << " " << u << endl;
      if (u <= a[i] && u <= b[i+1] && b[i+1]-u >= low && b[i+1]-u <= high2) {
        b[i] = u;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << " " << b[i+1] << '\n';
  }
}