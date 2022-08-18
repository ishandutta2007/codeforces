#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_L = 105;
const int MAX_T = 1005;

char cur [MAX_L];
vector<int> toToggle [MAX_T];

int main () {
  int lightc;
  cin >> lightc;

  int curOn = 0;
  for (int i = 0; i < lightc; i++) {
    cin >> cur[i];
    cur[i] -= '0';
    curOn += cur[i];
  }

  for (int i = 0; i < lightc; i++) {
    int a, b;
    cin >> a >> b;

    for (int j = b; j < MAX_T; j += a) {
      toToggle[j].push_back(i);
    }
  }

  int ans = curOn;
  for (int i = 0; i < MAX_T; i++) {
    for (int u : toToggle[i]) {
      curOn -= cur[u];
      cur[u] = !cur[u];
      curOn += cur[u];
    }

    ans = max(ans, curOn);
  }

  cout << ans << endl;
}