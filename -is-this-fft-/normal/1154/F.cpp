#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_SHOV = 2005;
const ll INF = 1e11;

ll cost [MAX_SHOV];
ll cumCost [MAX_SHOV];
int bestBargain [MAX_SHOV];
ll dp [MAX_SHOV];

int main () {
  int shovc, offerc, buyc;
  cin >> shovc >> offerc >> buyc;

  vector<int> shovels (shovc);
  for (int i = 0; i < shovc; i++) {
    cin >> shovels[i];
  }

  for (int i = 0; i < offerc; i++) {
    int num, freec;
    cin >> num >> freec;

    if (num <= MAX_SHOV) {
      bestBargain[num] = max(bestBargain[num], freec);
    }
  }
  
  sort(shovels.begin(), shovels.end());
  
  for (int i = 0; i < buyc; i++) {
    cost[i + 1] = shovels[i];
  }
  
  for (int i = 1; i <= buyc; i++) {
    cumCost[i] = cumCost[i - 1] + cost[i];
  }
  
  dp[0] = 0;
  for (int i = 1; i <= buyc; i++) {
    dp[i] = INF;
    for (int j = 0; j < i; j++) {
      int segLen = i - j;
      dp[i] = min(dp[i], dp[j] + cumCost[i] - cumCost[j + bestBargain[segLen]]);

      //    cout << i << " " << j << " " << dp[i] << " " << bestBargain[segLen] << endl;
    }
  }

  cout << dp[buyc] << endl;
}