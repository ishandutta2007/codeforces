#include <iostream>

using namespace std;

bool iswall [1005][1005];
int roomno [1005][1005], picc [1000005];
int width, height;

void scan (int row, int col, int num) {
  // cout << "Scanning " << row << " " << col << " " << num << endl;
  roomno[row][col] = num;
  if (iswall[row-1][col]) {
    picc[num]++;
  } else if (!roomno[row-1][col]) {
    scan(row-1, col, num);
  }
  // cout << iswall[row-1][col-1] << " " << roomno[row-1][col-1] << " ";

  if (iswall[row+1][col]) {
    picc[num]++;
  } else if (!roomno[row+1][col]) {
    scan(row+1, col, num);
  }
  // cout << iswall[row+1][col-1] << " " << roomno[row+1][col-1] << " ";

  if (iswall[row][col+1]) {
    picc[num]++;
  } else if (!roomno[row][col+1]) {
    scan(row, col+1, num);
  }
  // cout << roomno[row-1][col+1] << " ";

  if (iswall[row][col-1]) {
    picc[num]++;
  } else if (!roomno[row][col-1]) {
    scan(row, col-1, num);
  }
  // cout << roomno[row+1][col+1] << endl;
}

int main () {
  int queryc;
  char c;
  cin >> height >> width >> queryc;
  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width; j++) {
      cin >> c;
      if (c == 42) iswall[i][j] = true;
      // cout << iswall[i][j];
    }
    // cout << endl;
  }

  int maxrn = 1, row, col;
  for (int i = 0; i < queryc; i++) {
    cin >> row >> col;
    if (roomno[row][col]) {
      cout << picc[roomno[row][col]] << endl;
    } else {
      scan(row, col, maxrn);
      maxrn++;
      cout << picc[roomno[row][col]] << endl;
    }
  }
}