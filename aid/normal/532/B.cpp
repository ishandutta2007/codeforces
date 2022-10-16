#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int kN = 2 * 100 * 1000 + 1;

vector<int> g[kN];
vector<int> a;
ll dp[kN][2];

void DFS(int u) {
  
  dp[u][1] = a[u];
  dp[u][0] = 0;
  int m = g[u].size();
  vector<ll> diff(m);
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    DFS(v);
    dp[u][0] += dp[v][0];
    dp[u][1] += dp[v][0];
    diff[i] = dp[v][1] - dp[v][0];
  }
  ll sum = dp[u][0];
  sort(diff.rbegin(), diff.rend());
  for (int i = 1; i < m; i += 2) {
    if (dp[u][0] + diff[i - 1] + diff[i] < dp[u][0]) {
      break;
    }
    dp[u][0] += diff[i - 1] + diff[i];
    dp[u][1] += diff[i - 1] + diff[i];
  }
  if (m >= 1) {
    ll carry = diff[0];
    for (int i = 2; i < m; i += 2) {
      if (carry + diff[i - 1] + diff[i] < carry) {
        break;
      }
      carry += diff[i - 1] + diff[i];
    }
    dp[u][1] = max(dp[u][1], sum + carry);
  }
  /*
  cout << "u = " << u  + 1<< endl;
  cout << "dp_0 " << dp[u][0] << endl;
  cout << "dp_1 " << dp[u][1] << endl;
  */
}

int main() {
  std::ios_base::sync_with_stdio(false);
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    int p_, a_;
    cin >> p_ >> a_;
    if (p_ != -1) {
      g[p_ - 1].push_back(i);
    }
    a[i] = a_;
  }
  DFS(0);
  cout << max(dp[0][0], dp[0][1]);
  return 0;
}