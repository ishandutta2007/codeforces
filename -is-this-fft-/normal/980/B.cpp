#include <iostream>

using namespace std;

const int MAX_W = 105;
const int HEIGHT = 4;

char grid [HEIGHT][MAX_W];

int main () {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < MAX_W; j++) {
      grid[i][j] = '.';
    }
  }
  
  int width, hotelc;
  cin >> width >> hotelc;

  cout << "YES" << endl;
  if (hotelc % 2 == 0) {
    for (int i = 1; i <= hotelc / 2; i++) {
      grid[1][i] = '#';
      grid[2][i] = '#';
    }
  } else {
    if (hotelc <= width - 2) {
      for (int i = width / 2 - hotelc / 2; i < width / 2 - hotelc / 2 + hotelc; i++) {
        grid[1][i] = '#';
      }
    } else {
      for (int i = 1; i <= min(hotelc, width - 2); i++) {
        grid[1][i] = '#';
      }
      grid[2][width - 2] = '#';
      for (int i = width; i <= hotelc; i++) {
        grid[2][i - width + 1] = '#';
      }
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < width; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}