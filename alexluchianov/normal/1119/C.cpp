#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
int v[5 + nmax][5 + nmax], v2[5 + nmax][5 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= m;j++)
      cin >> v[i][j];
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= m;j++)
      cin >> v2[i][j];
  bool flag = 1;
  for(int i = 1;i <= n;i++){
    int result = 0;
    for(int j = 1;j <= m;j++){
      result += v[i][j] - v2[i][j];
    }
    if((2 + result % 2) % 2 == 1)
      flag = 0;
  }

  for(int j = 1; j <= m; j++) {
    int result = 0;
    for(int i = 1;i <= n;i++) {
      result += v[i][j] - v2[i][j];
    }

    if((2 + result % 2) % 2 == 1)
      flag = 0;
  }
  if(flag == 1)
    cout << "Yes";
  else
    cout << "No";

  return 0;
}