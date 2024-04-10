#include <iostream>

const int MAX_ACTOR = 1005;

using namespace std;

int actors [MAX_ACTOR][MAX_ACTOR];

int main () {
  int height, width;
  cin >> height >> width;

  int actorc = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> actors[i][j];
      if (actors[i][j]) {
        actorc++;
      }
    }
  }

  int ans = height * width * 4 - actorc * 4;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (actors[i][j]) {
        break;
      } else {
        ans--;
      }
    }
  }

  for (int j = 0; j < width; j++) {
    for (int i = 0; i < height; i++) {
      if (actors[i][j]) {
        break;
      } else {
        ans--;
      }
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = width - 1; j >= 0; j--) {
      if (actors[i][j]) {
        break;
      } else {
        ans--;
      }
    }
  }

  for (int j = 0; j < width; j++) {
    for (int i = height - 1; i >= 0; i--) {
      if (actors[i][j]) {
        break;
      } else {
        ans--;
      }
    }
  }

  cout << ans << endl;
}