#include <iostream>

const int MAX_HEIGHT = 15;

using namespace std;

int val [MAX_HEIGHT][MAX_HEIGHT];

int main () {
  int height, seconds;
  cin >> height >> seconds;

  for (int i = 0; i < seconds; i++) {
    val[0][0]++;
    for (int j = 0; j < height; j++) {
      for (int k = 0; k <= j; k++) {
        if (val[j][k] > (1 << j)) {
          val[j + 1][k] += val[j][k] - (1 << j);
          val[j + 1][k + 1] += val[j][k] - (1 << j);
          val[j][k] = 1 << j;
        }
      }
    }
  }


  int ans = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < height; j++) {
      if (val[i][j] == 1 << i) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}