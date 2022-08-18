#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;
const int MAX_M = 105;
const int INF = 1e6 + 5;

int arr [MAX_M][MAX_N];
vector<int> sol;
int statc;

int dp [MAX_M][MAX_M];
int last [MAX_M][MAX_M];
void solve_for (int u, int v) { // u wants to win against v
  dp[0][0] = 0;
  for (int i = 1; i <= statc; i++) {
    dp[i][0] = dp[i - 1][0] + arr[i][u] - arr[i][v];
    last[i][0] = 0;
    for (int j = 1; j <= i; j++) {
      dp[i][j] = dp[i - 1][j - 1];
      last[i][j] = j - 1;

      if (dp[i - 1][j] + arr[i][u] - arr[i][v] > dp[i][j]) {
        dp[i][j] = dp[i - 1][j] + arr[i][u] - arr[i][v];
        last[i][j] = j;
      }
    }
  }

  int k = -1;
  for (int i = 0; i <= statc; i++) {
    if (dp[statc][i] >= 0) {
      k = i;
      break;
    }
  }

  vector<int> nsol;
  int curj = k;
  for (int i = statc; i > 0; i--) {
    if (last[i][curj] != curj) {
      nsol.push_back(i);
      curj--;
    }
  }

  if ((int) nsol.size() < (int) sol.size()) {
    sol = nsol;
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int cands;
  cin >> cands >> statc;

  for (int i = 1; i <= statc; i++) {
    for (int j = 1; j <= cands; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= statc; i++) {
    sol.push_back(i);
  }
  
  for (int i = 1; i < cands; i++) {
    solve_for(i, cands);
  }

  cout << (int) sol.size() << endl;
  for (int u : sol) {
    cout << u << " " ;
  }
  cout << endl;
}