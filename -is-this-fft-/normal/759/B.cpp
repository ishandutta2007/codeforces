#include <iostream>
#include <queue>

const int MAX_TRIP = 100005;
const int INF = 1023456789;

using namespace std;

int trips [MAX_TRIP], influence [MAX_TRIP][2]; /* first i that doesn't work */
int dp [MAX_TRIP]; /* optimal cost after making trip i */

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_TRIP; i++) {
    dp[i] = INF;
  }

  int tripc;
  cin >> tripc;

  queue<int> hourtrips;
  queue<int> daytrips;
  for (int i = 0; i < tripc; i++) {
    cin >> trips[i];
    hourtrips.push(i);
    daytrips.push(i);

    while (!hourtrips.empty() && trips[i] - trips[hourtrips.front()] >= 90) {
      influence[hourtrips.front()][0] = i;
      hourtrips.pop();
    }

    while (!daytrips.empty() && trips[i] - trips[daytrips.front()] >= 1440) {
      influence[daytrips.front()][1] = i;
      daytrips.pop();
    }
  }

  while (!hourtrips.empty()) {
    influence[hourtrips.front()][0] = tripc;
    hourtrips.pop();
  }

  while (!daytrips.empty()) {
    influence[daytrips.front()][1] = tripc;
    daytrips.pop();
  }

  for (int i = 0; i < tripc; i++) {
    int prev;
    if (i == 0) {
      prev = 0;
    } else {
      prev = dp[i - 1];
    }

    dp[i] = min(dp[i], prev + 20);

    for (int j = i; j < influence[i][0]; j++) {
      dp[j] = min(dp[j], prev + 50);
    }

    for (int j = i; j < influence[i][1]; j++) {
      dp[j] = min(dp[j], prev + 120);
    }

    cout << dp[i] - prev << '\n';
  }
}