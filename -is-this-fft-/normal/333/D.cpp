#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1005;

int matrix [maxn][maxn];
int exists [maxn][maxn];

int main () {
  ios::sync_with_stdio(false);
  
  int height, width;
  cin >> height >> width;

  vector<pair<int, pair<int, int>>> pos;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int x;
      cin >> x;

      pos.push_back(make_pair(x, make_pair(i, j)));
    }
  }

  sort(pos.begin(), pos.end(), greater<pair<int, pair<int, int>>>());
  for (pair<int, pair<int, int>> elem : pos) {
    int r = elem.second.first;
    int c = elem.second.second;

    matrix[r][c] = 1;
    for (int i = 0; i < height; i++) {
      if (i != r) {
        if (matrix[i][c]) {
          if (exists[r][i]) {
            cout << elem.first << endl;
            return 0;
          }
          exists[r][i] = 1;
          exists[i][r] = 1;
        }
      } 
    } 
  }
}