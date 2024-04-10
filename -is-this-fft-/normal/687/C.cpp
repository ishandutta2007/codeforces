#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 505;

bool dp [MAX_N][MAX_N][MAX_N];
bool ans [MAX_N];

int main () {
  int n, K;
  cin >> n >> K;

  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int add;
    cin >> add;

    for (int j = 0; j < MAX_N; j++) {
      for (int k = 0; k < MAX_N; k++) {
        dp[i][j][k] |= dp[i - 1][j][k];
      }
    }
    
    for (int j = 0; j < MAX_N; j++) {
      for (int k = 0; k + add < MAX_N; k++) {
        dp[i][j][k + add] |= dp[i - 1][j][k];
      }
    }

    for (int j = 0; j + add < MAX_N; j++) {
      for (int k = 0; k < MAX_N; k++) {
        dp[i][j + add][k] |= dp[i - 1][j][k];
      }
    }
  }

  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      if (i + j == K && dp[n][i][j]) {
        ans[i] = 1;
        ans[j] = 1;
      }
    }
  }

  vector<int> v;
  for (int i = 0; i < MAX_N; i++) {
    if (ans[i]) v.push_back(i);
  }

  cout << (int) v.size() << '\n';
  for (int u : v) {
    cout << u << " ";
  }
  cout << '\n';
}