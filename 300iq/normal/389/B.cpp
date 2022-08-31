#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  char c[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
      cin >> c[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (c[i][j] == '#') {
        if (c[i + 1][j] == '#' && c[i + 1][j - 1] == '#' && c[i + 1][j + 1] == '#' && c[i + 2][j] == '#')
          c[i][j] = c[i + 1][j] = c[i + 1][j - 1] = c[i + 1][j + 1] = c[i + 2][j] = '.';
        else if (c[i - 1][j] == '#' && c[i + 1][j] == '#' && c[i][j - 1] == '#' && c[i][j + 1] == '#')
          c[i][j] = c[i - 1][j] = c[i + 1][j] = c[i][j - 1] = c[i][j + 1] = '.';
        else if (c[i - 1][j + 1] == '#' && c[i + 1][j + 1] == '#' && c[i][j + 2] == '#' && c[i][j + 1] == '#')
          c[i][j] = c[i - 1][j] = c[i + 1][j] = c[i][j - 1] = c[i][j + 1] = '.';
        else if (c[i][j - 2] == '#' && c[i][j - 1] == '#' && c[i + 1][j - 1] == '#' && c[i - 1][j - 1] == '#')
          c[i][j] = c[i][j - 2] = c[i][j - 1] = c[i + 1][j - 1] = c[i - 1][j - 1] = '.';
        else {
	      cout << "NO" << endl;
		  return 0;
		}
      }
  cout << "YES" << endl;
}