#include <iostream>

const int MAX_W = 15;

using namespace std;

bool viola [MAX_W][MAX_W];
int violac [MAX_W][MAX_W];

int main () {
  int height, width, violas, minv;
  cin >> height >> width >> violas >> minv;

  for (int i = 0; i < violas; i++) {
    int r, c;
    cin >> r >> c;
    viola[r][c] = true;
  }

  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width; j++) {
      violac[i][j] = violac[i][j - 1] + viola[i][j];
    }
   
    for (int j = 1; j <= width; j++) {
      violac[i][j] += violac[i - 1][j];
    }
  }

  int ans = 0;
  for (int lr = 1; lr <= height; lr++) {
    for (int hr = lr; hr <= height; hr++) {
      for (int lc = 1; lc <= width; lc++) {
	for (int hc = lc; hc <= width; hc++) {
	  if (violac[hr][hc] - 
	      violac[lr - 1][hc] -
	      violac[hr][lc - 1] +
	      violac[lr - 1][lc - 1] >= minv) {
	    ans++;
	  }
	}
      }
    }
  }

  cout << ans << endl;
}