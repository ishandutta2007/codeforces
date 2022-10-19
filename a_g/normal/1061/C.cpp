#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+5;
int dp[N];
vector<int> divs[N];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = N-1; i >= 1; i--) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int d: divs[x]) {
      add(dp[d], dp[d-1]);
    }
  }
  int ans = 0;
  for (int i = 1; i < N; i++) add(ans, dp[i]);
  cout << ans << '\n';
}