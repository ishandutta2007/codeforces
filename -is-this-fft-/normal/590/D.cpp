#include <iostream>

const int MAX_SWAP = 22555; 
const int MAX_SOLD = 155;
const long long INF = 1LL << 62;

using namespace std;

long long loquac [MAX_SOLD];
long long dp [MAX_SWAP][2][MAX_SOLD]; 
long long pref [MAX_SOLD];

/* dp[k][i][j] is
 * minimum loquac done with k swaps
 * of a troop size i,
 * with soldiers picked from first j
 */

int main () {
  for (int k = 0; k < MAX_SWAP; k++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < MAX_SOLD; j++) {
	dp[k][i][j] = INF;
      }
    }
  }

  int soldc, troops, swapc;
  cin >> soldc >> troops >> swapc;
  for (int i = 0; i < soldc; i++) {
    cin >> loquac[i];
    if (i == 0) {
      pref[i] = loquac[i];
    } else {
      pref[i] = pref[i - 1] + loquac[i];
    }
  }

  dp[0][0][0] = 0;

  for (int i = 0; i <= troops; i++) {
    if (i != 0) {
      dp[0][i % 2][i] = pref[i - 1];
    }

    for (int k = 0; k <= soldc * soldc && k <= swapc; k++) {
      for (int j = i; j <= soldc; j++) {
	if (j >= 1) {
	  dp[k][i % 2][j] = min(dp[k][i % 2][j], dp[k][i % 2][j - 1]);
	}
	if (dp[k][i % 2][j] != INF) {
	  dp[k + (j - i)][(i + 1) % 2][j + 1] = dp[k][i % 2][j] + loquac[j];
	}
      }
    }

    if (i != troops) {
      for (int k = 0; k <= soldc * soldc && k <= swapc; k++) {
	for (int j = 0; j <= soldc; j++) {
	  dp[k][i % 2][j] = INF;
	}
      }
    }
  }
  
  long long bestk = INF;
  for (int i = 0; i <= soldc * soldc && i <= swapc; i++) {
    if (dp[i][troops % 2][soldc] < bestk) {
      bestk = dp[i][troops % 2][soldc];
    }
  }

  cout << bestk << endl;
}