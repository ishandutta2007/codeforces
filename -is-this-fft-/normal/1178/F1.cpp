#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 510;
const int MOD = 998244353;

typedef long long ll;

ll dp [MAX_N][MAX_N];

void solve (int colorc, int length, vector<int> arr) {
  for (int l = 0; l <= length + 5; l++) {
    for (int r = 0; r <= length + 5; r++) {
      if (r <= l) {
        dp[l][r] = 1;
      }
    }
  }
  
  for (int k = 1; k < length; k++) {
    for (int l = 1; l + k <= length; l++) {
      int r = l + k;

      pair<int, int> dom = make_pair(MOD, -1);
      for (int i = l; i <= r; i++) {
        dom = min(make_pair(arr[i], i), dom);
      }

      dp[l][r] = 1;
      ll leftmul = 0;
      for (int i = l; i <= dom.second; i++) {
        leftmul += (dp[l][i - 1] * dp[i][dom.second - 1]) % MOD;
        leftmul %= MOD;
      }

      ll rightmul = 0;
      for (int i = dom.second; i <= r; i++) {
        rightmul += (dp[dom.second + 1][i] * dp[i + 1][r]) % MOD;
        rightmul %= MOD;

      }

      dp[l][r] = leftmul * rightmul % MOD;
    }
  }

  cout << dp[1][length] << endl;
}

int main () {
  int colorc, length;
  cin >> colorc >> length;

  vector<int> arr (length + 1);
  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  solve(colorc, length, arr);
}