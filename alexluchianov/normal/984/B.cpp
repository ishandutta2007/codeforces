#include <iostream>

using namespace std;

int const iplus[8] = {0 , 0 , 1 , 1 , 1,  -1 , -1 , -1};
int const jplus[8] = {1 , -1 , 0 , 1 ,-1 , 0 , 1 , -1};

int const nmax = 100;
char v[5 + nmax][5 + nmax] = {0};

bool valid(int x , int y){
  if(v[x][y] == '*')
    return 1;

  int sum = 0;
  for(int h = 0 ; h < 8 ;h++)
    sum += (v[x + iplus[h]][y + jplus[h]] == '*' );
  if((sum == (v[x][y] - '0')) || (sum == 0 && v[x][y] == '.'))
    return 1;
  else
    return 0;
}

int main()
{
  int n , m ;
  cin >> n >> m;
  for(int i = 1 ; i <= n ;i++)
    for(int j = 1 ; j <= m ;j++)
      cin >> v[i][j];

  for(int i = 1 ; i <= n ;i++)
    for(int j = 1 ; j <= m ;j++)
      if(valid(i , j) == 0){
        cout << "NO\n";
        return 0;
      }
  cout << "YES\n";
  return 0;
}