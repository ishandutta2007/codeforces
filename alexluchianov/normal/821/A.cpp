#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
int v[1 + nmax][1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      cin >> v[i][j];
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      if(1 < v[i][j]) {
        bool ok = 0;
        for(int x = 1;x <= n; x++)
          for(int y = 1; y <= n; y++)
            if(v[i][y] + v[x][j] == v[i][j])
              ok = 1;
        if(ok == 0) {
          cout << "No\n";
          return 0;
        }
      }
  cout << "Yes\n";
  return 0;
}