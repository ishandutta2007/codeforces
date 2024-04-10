#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+100;

int solve(vector<int>& a) {
  int n = a.size();
  int m = max_element(a.begin(), a.end())-a.begin();
  vector<array<int, 2>> dp1(m+1, {-INF, -INF});
  for (int i = 0; i <= m; i++) {
    if (i > 0) dp1[i] = dp1[i-1];
    if (a[i] > dp1[i][1]) {
      dp1[i][1] = a[i];
    }
    else if (a[i] > dp1[i][0]) {
      dp1[i][0] = a[i];
    }
    else {
      dp1[i][0] = INF;
      dp1[i][1] = INF;
    }
  }
  vector<array<int, 2>> dp2(n, {-INF, INF}), dp3(n, {-INF, -INF});
  for (int i = n-1; i >= m; i--) {
    if (i < n-1) dp3[i] = dp3[i+1];
    if (a[i] > dp3[i][1]) {
      dp3[i][1] = a[i];
    }
    else if (a[i] > dp3[i][0]) {
      dp3[i][0] = a[i];
    }
    else {
      dp3[i][0] = INF;
      dp3[i][1] = INF;
    }
  }

  // dp2[i][0] = maximum possible value of seq1 given that a[i] is in seq2
  // dp2[i][1] = minimum possible value of seq2 given that a[i] is in seq1
  dp2[m][1] = dp1[m][0];
  for (int i = m; i < n-1; i++) {
    if (a[i+1] < a[i]) {
      dp2[i+1][1] = min(dp2[i+1][1], dp2[i][1]);
    }
    if (a[i+1] > a[i]) {
      dp2[i+1][0] = max(dp2[i+1][0], dp2[i][0]);
    }
    if (a[i+1] < dp2[i][0]) {
      dp2[i+1][1] = min(dp2[i+1][1], a[i]);
    }
    if (a[i+1] > dp2[i][1]) {
      dp2[i+1][0] = max(dp2[i+1][0], a[i]);
    }
  }
  int ans = 0;
  for (int i = m; i < n; i++) {
    int other;
    if (dp3[i][0] == a[i]) {
      other = dp3[i][1];
    }
    else if (dp3[i][1] == a[i]) {
      other = dp3[i][0];
    }
    else {
      continue;
    }
    if (dp2[i][0] > other) {
      ans++;
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = solve(a);
  reverse(a.begin(), a.end());
  ans += solve(a);
  cout << ans << '\n';
}