#include <iostream>
#include <string>

typedef long long llong;

const int MAX_SUM = 2655;
const int MAX_LENGTH = 105;
const int MOD = 1000000007;

using namespace std;

llong ans [MAX_LENGTH][MAX_SUM];

/* # of ways to make i partitions on the first j*/

int main () {
  ans[0][0] = 1;
  for (int i = 1; i < MAX_LENGTH; i++) {
    for (int j = 1; j < MAX_SUM; j++) {
      for (int k = 1; k <= 26; k++) {
        if (j - k >= 0) {
          ans[i][j] += ans[i - 1][j - k];
          ans[i][j] %= MOD;
        }
      }
    }
  }

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    string str;
    cin >> str;

    int sum = 0;
    for (int i = 0; i < (int) str.size(); i++) {
      sum += str[i] - 'a' + 1;
    }
    
    cout << ans[(int) str.size()][sum] - 1<< "\n";
  }
}