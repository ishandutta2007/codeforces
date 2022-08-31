#include <iostream>

using namespace std;

long long ncr [800][8];

int main () {
  ncr[0][0] = 1LL;
  for (int i = 1; i < 800; i++) {
    ncr[i][0] = 1LL;
    for (int j = 1; j < 8; j++) {
      ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    }
  }

  int peoplec;
  cin >> peoplec;
  cout << ncr[peoplec][5] + ncr[peoplec][6] + ncr[peoplec][7]
       << endl;
}