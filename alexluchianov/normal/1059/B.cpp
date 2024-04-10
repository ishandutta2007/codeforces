#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const iplus[8] = {0 , 0 , 1 , 1 , 1 , -1 , - 1 , -1};
int const jplus[8] = {1 , - 1 , 0 , 1 , -1 , 0 , 1 , -1};


int color[5 + nmax][5 + nmax];
int target[5 + nmax][5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n , m;
  cin >> n >> m;

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      char a;
      cin >> a;
      if(a == '#')
        target[i][j] = 1;
    }
  }
  for(int i = 2 ; i < n ; i++)
    for(int j = 2 ; j < m ; j++) {
      bool ok = 1;
      for(int h = 0 ; h < 8 ; h++){
        int newx = i + iplus[h];
        int newy = j + jplus[h];
        ok &= target[newx][newy];
      }
      if(ok == 1)
        for(int h = 0 ; h < 8 ; h++){
          int newx = i + iplus[h];
          int newy = j + jplus[h];
          color[newx][newy] = 1;
        }
    }
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++)
      if(color[i][j] != target[i][j]) {
        cout << "NO";
        return 0;
      }

  cout << "YES";
  return 0;
}