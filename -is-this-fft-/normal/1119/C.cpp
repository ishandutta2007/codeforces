#include <iostream>

using namespace std;

const int MAX_N = 505;

int grid [MAX_N][MAX_N];

int main () {
  int height, width;
  cin >> height >> width;
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> grid[i][j];
    }
  }

  int sum = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int x;
      cin >> x;
      grid[i][j] ^= x;

      sum ^= grid[i][j];
    }
  }

  bool ok = true;
  for (int i = 0; i < height; i++) {
    int rsum = 0;
    for (int j = 0; j < width; j++) {
      rsum ^= grid[i][j];
    }

    if (rsum != 0) {
      ok = false;
    }
  }

  for (int j = 0; j < width; j++) {
    int csum = 0;
    for (int i = 0; i < height; i++) {
      csum ^= grid[i][j];
    }

    if (csum != 0) {
      ok = false;
    }
  }

  if (sum == 0 && ok) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}