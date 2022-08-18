#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 105;
const int MAX_M = 1e6 + 5;

int conn [MAX_N][MAX_N];
int dist [MAX_N][MAX_N];
int path [MAX_M];
pair<int, int> dp [MAX_M];

int main () {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char c;
      cin >> c;
      
      conn[i][j] = c - '0';
      if (i == j) {
        dist[i][j] = 0;
      } else if (conn[i][j] == 0) {
        dist[i][j] = MAX_N;
      } else {
        dist[i][j] = 1;
      }
    }
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> path[i];
  }

  dp[0] = make_pair(0, -1);
  for (int i = 1; i < M; i++) {
    dp[i] = make_pair(i, i - 1);
    for (int j = i - 1; j >= max(0, i - MAX_N); j--) {
      if (dist[path[j]][path[i]] == i - j) {
        dp[i] = min(dp[i], make_pair(dp[j].first + 1, j));
      }
    }
  }

  vector<int> ans;
  for (int u = M - 1; u != -1; u = dp[u].second) {
    ans.push_back(path[u]);
  }
  reverse(ans.begin(), ans.end());

  cout << (int) ans.size() << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}