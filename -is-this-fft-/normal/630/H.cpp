#include <iostream>

const long long FFACT = 120;

using namespace std;

long long ncr [105][6];

int main () {
  ncr[0][0] = 1LL;
  for (int i = 1; i < 105; i++) {
    ncr[i][0] = 1LL;
    for (int j = 1; j < 6; j++) {
      ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    }
  }

  int pathc;
  cin >> pathc;

  cout << ncr[pathc][5] * ncr[pathc][5] * FFACT << endl;
}