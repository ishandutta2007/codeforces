#include <iostream>
#include <fstream>

using namespace std;

int const nmax = 100;
char v[1 + nmax][1 + nmax];

int main()
{
  int n;
  cin >> n;
  if(n == 5)
    cout << ">...v\nv.<..\n..^..\n>....\n..^.<\n1 1";
  else if(n == 3)
    cout << ">vv\n^<.\n^.<\n1 3";
  else {
    for(int i = 1;i <= n; i++)
      for(int j = 1;j <= n; j++)
        v[i][j] = '.';
    int split = n / 3;
    for(int i = 1;i <= n; i += 2){
      for(int j = 1; j <= split; j++)
        v[i][j] = '>';
      for(int j = split + 2; j < n; j += 2)
        v[i][j] = '>';
      v[i][n] = 'v';
      v[i + 1][1] = '^';
      for(int j = n - split; j <= n; j++)
        v[i + 1][j] = '<';
      for(int j = n - split - 2; 2 <= j; j -= 2)
        v[i + 1][j] = '<';
    }

    for(int i = 1;i <= n; i++) {
      for(int j = 1;j <= n; j++)
        cout << v[i][j];
      cout << '\n';
    }
    cout << n - 1 << " " << n;
  }
  return 0;
}