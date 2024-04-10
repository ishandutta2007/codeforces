#include <iostream>

const int MAX_HEIGHT = 1005;

using namespace std;

int rowsum [MAX_HEIGHT];
int colsum [MAX_HEIGHT];
bool bomb [MAX_HEIGHT][MAX_HEIGHT];

int main () {
  int height, width;
  cin >> height >> width;

  int bombc = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      char c;
      cin >> c;
      if (c == '*') {
        rowsum[i]++;
        colsum[j]++;
        bomb[i][j] = true;
        bombc++;
      }
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (rowsum[i] + colsum[j] - bomb[i][j] == bombc) {
        cout << "YES\n" << i + 1 << " " << j + 1 << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
}