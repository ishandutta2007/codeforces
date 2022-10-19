#include <bits/stdc++.h>
using namespace std;

const int N = 82;
const int INF = 1e9;
int dp[N][N][N*N];
// (number of steps, prefix sum, operations) -> minimum sum of squares

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  int curr = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x) {
      a.push_back(curr);
      curr = 0;
    }
    else curr++;
  }
  a.push_back(curr);
  int d = a.size();
  vector<int> s(d+1);
  for (int i = 0; i < d; i++) {
    s[i+1] = s[i] + a[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N*N; k++) {
        dp[i][j][k] = INF;
      }
    }
  }

  int max_op = n*(n-1)/2;

  dp[0][0][0] = 0;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j <= s[d]; j++) {
      for (int k = 0; k <= max_op; k++) {
        if (dp[i][j][k] != INF) {
          for (int l = j; l <= s[d]; l++) {
            dp[i+1][l][k+abs(s[i+1]-l)] = min(dp[i+1][l][k+abs(s[i+1]-l)], dp[i][j][k] + (l-j)*(l-j));
          }
        }
      }
    }
  }

  vector<int> ans(n*(n-1)/2+1);
  for (int k = 0; k <= max_op; k++) {
    ans[k] = (s[d]*s[d]-dp[d][s[d]][k])/2;
  }
  for (int k = 0; k < max_op; k++) {
    ans[k+1] = max(ans[k+1], ans[k]);
  }

  for (int val: ans) cout << val << ' ';
  cout << '\n';
}