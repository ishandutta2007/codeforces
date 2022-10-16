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

const int kT = 101, kN = 2000;

const int kInf = 1000 * 1000 * 1000;

int dp[kT][kN];
int q[kN];
int t[kN];

int T;
int n;

vector<int> g[kT];

int DP(int h, int k) {
  if(k > n || k < 0)
    return -kInf;
  int H = T - h ;
  if (h == T - 1) {
    if(dp[h][k] != -1)
      return dp[h][k];
    if (k > g[H].size()) {
      return -kInf; 
    }
    int res = 0;
    for (int i = 0; i < k; ++i) {
      res += g[H][i];
    }
    dp[h][k] = res;
    return res;
  }
  if (dp[h][k] == -1) {
    dp[h][k] = max(DP(h + 1, 2 * k), DP(h + 1, 2 * k - 1));
    int sum = 0;
    for (int i = 1; i <= min(k, (int)g[H].size()); ++i) {
      sum += g[H][i - 1]; 
      int curr = max(DP(h + 1, 2 * (k - i)), DP(h + 1, 2 * (k - i) - 1));
      dp[h][k] = max(dp[h][k], curr + sum);
    }
  }
  return dp[h][k];
}

bool Cmp(int lhs, int rhs) {
  return lhs > rhs;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  cin >> n >> T;
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> q[i];
    g[t[i]].push_back(q[i]);
  }
  for (int i = 0; i <= T; ++i) {
    sort(g[i].begin(), g[i].end(), Cmp);
  }
  // cout << "!" << endl;
  memset(dp, 255, sizeof(dp));
  cout << max(0, DP(0, 1));
  return 0;
}