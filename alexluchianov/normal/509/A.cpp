#include <iostream>

using namespace std;

int const nmax = 100;
int v[5 + nmax][5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ;i <= n ; i++)
    v[i][1] = v[1][i] = 1;

  for(int i = 2 ; i <= n ; i++)
    for(int j = 2 ; j <= n ; j++)
      v[i][j] = v[i - 1][j] + v[i][j - 1];
  cout << v[n][n];
  return 0;
}