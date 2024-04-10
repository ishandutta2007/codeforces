#include <iostream>
#include <string>

using namespace std;

const int MAX_B = 200;

string grid [MAX_B];

int main () {
  int height, width;
  cin >> height >> width;

  int xmax = -1, xmin = MAX_B, ymax = -1, ymin = MAX_B;

  for (int i = 0; i < height; i++) {
    cin >> grid[i];
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == 'B') {
        xmax = max(xmax, i);
        xmin = min(xmin, i);
        ymax = max(ymax, j);
        ymin = min(ymin, j);
      }
    }
  }

  cout << (xmax + xmin) / 2 + 1 << " " << (ymax + ymin) / 2 + 1 << endl;
}