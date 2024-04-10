#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
char v[1 + nmax][1 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      v[i][j] = '.';
  for(int i = 1;i <= n; i ++)
    if(i % 2 == 1)
      for(int j = 1;j <= m; j++)
        v[i][j] = '#';
    else {
      if(i % 4 == 2)
        v[i][m] = '#';
      else
        v[i][1] = '#';
    }

  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= m; j++)
      cout << v[i][j];
    cout << '\n';
  }
  return 0;
}