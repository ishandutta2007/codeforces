#include <iostream>
#include <vector>

const int MAX_COL = 100000;

using namespace std;

int jump [MAX_COL];

int main () {
  for (int i = 0; i < MAX_COL; i++) {
    jump[i] = i;
  }

  int height, width;
  cin >> height >> width;
  vector<vector<int> > table (height + 5, vector<int> (width + 5, 0));

  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width; j++) {
      cin >> table[i][j];
    }
  }

  for (int j = 1; j <= width; j++) {
    int curs = 1;
    for (int i = 2; i <= height; i++) {
      if (table[i][j] < table[i - 1][j]) {
        for (int k = i - 1; k >= curs; k--) {
          jump[k] = max(jump[k], i - 1);
        }
      
        curs = i;
      }
    }

    for (int k = height; k >= curs; k--) {
      jump[k] = max(jump[k], height);
    }
  }
  
  int queryc;
  cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    int up, down;
    cin >> up >> down;

    if (jump[up] >= down) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}