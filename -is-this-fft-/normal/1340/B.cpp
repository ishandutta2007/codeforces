#include <iostream>
#include <bitset>
#include <string>

using namespace std;

typedef bitset<7> disp;

void failure () {
  cout << -1 << endl;
  exit(0);
}

disp nums [10] =
  {disp(string("1110111")),
   disp(string("0010010")),
   disp(string("1011101")),
   disp(string("1011011")),
   disp(string("0111010")),
   disp(string("1101011")),
   disp(string("1101111")),
   disp(string("1010010")),
   disp(string("1111111")),
   disp(string("1111011"))};

int cost (disp cur, disp tar) {
  if ((cur | tar) != tar) {
    return 4000;
  } else {
    return (cur ^ tar).count();
  }
}

const int MAX_N = 2005;

disp arr [MAX_N];
int dp [MAX_N][MAX_N]; // <position, taken>

int main () {
  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    arr[i] = disp(s);
  }

  for (int i = 0; i < n + 1; i++) {
    for (int k = 0; k < MAX_N; k++) {
      dp[i][k] = -1;
    }
  }

  dp[n][0] = -2;
  
  for (int i = n - 1; i >= 0; i--) {
    for (int k = 0; k < MAX_N; k++) {
      if (dp[i + 1][k] != -1) {
        for (int j = 0; j <= 9; j++) {
          int c = cost(arr[i], nums[j]);
          if (k + c < MAX_N) {
            dp[i][k + c] = max(dp[i][k + c], j);
          }
        }
      }
    }
  }

  if (dp[0][K] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int k = K;
  for (int i = 0; i < n; i++) {
    cout << dp[i][k];
    k -= cost(arr[i], nums[dp[i][k]]);
  }
  cout << endl;
}