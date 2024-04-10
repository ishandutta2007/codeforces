#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
int const iplus[5] = {0 , 1 , 1 , -1 , -1};
int const jplus[5] = {0 , 1 , -1 , 1 , -1};
char v[5 + nmax][5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j <= n ; j++)
      cin >> v[i][j];

  int result = 0;
  for(int i = 2 ; i < n ; i++)
    for(int j = 2 ; j < n ; j++) {
      bool ok = 1;
      for(int h = 0 ; h < 5 ; h++)
        if(v[i + iplus[h]][j + jplus[h]] == '.')
          ok = 0;
      result += ok;
    }
  cout << result;
  return 0;
}