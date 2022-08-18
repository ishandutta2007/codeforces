#include <iostream>

typedef long long llong;

const int MAX_LEN = 100005;
const int MAX_QUERY = 505;
const llong INF = 1e18;

using namespace std;

llong val [MAX_LEN], color [MAX_LEN], dp [MAX_LEN];

int main () {  
  llong length, queryc;
  cin >> length >> queryc;

  for (llong i = 0; i < length; i++) {
    cin >> val[i];
  }

  for (llong i = 0; i < length; i++) {
    cin >> color[i];
  }

  for (llong i = 0; i < queryc; i++) {
    llong samec, diffc;
    cin >> samec >> diffc;

    dp[0] = 0;
    for (llong j = 1; j < MAX_LEN; j++) {
      dp[j] = -INF;
    }

    llong best = 0, sbest = 0;
    for (llong j = 0; j < length; j++) {
      llong samev = max(dp[color[j]], dp[color[j]] + samec * val[j]);
      llong diffv;
      if (color[j] == best) {
        diffv = max(dp[color[j]], dp[sbest] + diffc * val[j]);
      } else {
        diffv = max(dp[color[j]], dp[best] + diffc * val[j]);
      }
      
      dp[color[j]] = max(samev, diffv);
      if (dp[color[j]] > dp[best]) {
        sbest = best;
        best = color[j];
      } else if (dp[color[j]] > dp[sbest] && color[j] != best) {
        sbest = color[j];
      }
    }

    cout << dp[best] << endl;
  }
}