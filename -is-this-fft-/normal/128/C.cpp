#include <iostream>

typedef long long llong;

const int MAX_WIDTH = 2005;
const int MOD = 1000000007;

using namespace std;

llong choose [MAX_WIDTH][MAX_WIDTH];

int main () {
  choose[0][0] = 1;
  for (int i = 1; i < MAX_WIDTH; i++) {
    choose[i][0] = 1;
    for (int j = 1; j < MAX_WIDTH; j++) {
      choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
    }
  }

  int height, width, turnc;
  cin >> height >> width >> turnc;

  cout << (choose[height - 1][2 * turnc] * choose[width - 1][2 * turnc]) % MOD << endl;
}