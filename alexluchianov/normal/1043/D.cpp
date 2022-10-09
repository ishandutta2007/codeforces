#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) :(b))
#define MAX(a , b) (((a) < (b)) ? (b) :(a))

int const nmax = 100000;

int v[15][5 + nmax];
int frec[15][5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m , n;
  cin >> m >> n;

  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ;j <= m ; j++) {
      cin >> v[i][j];
      frec[i][v[i][j]] = j;
    }

  int st = 1;

  ll result = 0;

  for(int i = 1 ; i <= m ; i++){

    if(st == i){
      result ++;
      continue;
    } else {
      int v1 = v[1][i - 1];
      int v2 = v[1][i];


      for(int j = 1 ; j <= n ; j++)
        if(frec[j][v1] + 1 != frec[j][v2])
          st = i;


      result += i - st + 1;
    }
  }

  cout << result;

  return 0;
}