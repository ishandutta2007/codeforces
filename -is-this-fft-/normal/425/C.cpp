#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_K = 305;
const int INF = 1e9 + 500;

int A [MAX_N];
int B [MAX_N];
int dp [MAX_N][MAX_K];

set<int> pos_B [MAX_N];

int first_after (int pos, int val) {
  auto ub = pos_B[val].upper_bound(pos);
  if (ub == pos_B[val].end()) return INF;
  return *ub;
}

int tot [MAX_K];

int main () {
  ios::sync_with_stdio(false);

  int n, m, S, E;
  cin >> n >> m >> S >> E;

  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> B[i];
    pos_B[B[i]].insert(i);
  }

  for (int i = 1; i < MAX_K; i++) {
    tot[i] = INF;
  }
  
  for (int i = 0; i < MAX_N; i++) {
    dp[i][0] = 0;
    for (int j = 1; j < MAX_K; j++) {
      dp[i][j] = INF;
    }
  }

  for (int i = 1; i < MAX_N; i++) {
    for (int j = 1; j < MAX_K; j++) {
      dp[i][j] = dp[i - 1][j];
      dp[i][j] = min(dp[i][j], first_after(dp[i - 1][j - 1], A[i]));
      tot[j] = min(tot[j], i + dp[i][j]);
    }
  }

  int ans = 0;
  for (int k = 1; k < MAX_K; k++) {
    int energy = S - k * E;
    if (energy <= 0) break;
    if (tot[k] > energy) break;
    ans = k;
  }

  cout << ans << endl;
}