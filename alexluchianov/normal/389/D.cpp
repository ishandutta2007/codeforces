#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 92;
bool v[5 + nmax][5 + nmax];


int main()
{
  int k;
  cin >> k;
  v[1][3] = v[3][1] = 1;
  v[1][4] = v[4][1] = 1;

  int p = 63;
  for(int i = 2 ; i <= 30 ; i++){
    v[i * 2 - 1][i * 2 + 1] = 1;
    v[i * 2 - 1][i * 2 + 2] = 1;
    v[i * 2][i * 2 + 1] = 1;
    v[i * 2][i * 2 + 2] = 1;
  }

  for(int i = 0 ; i < 29 ; i++)
    v[p + i][p + i + 1] = 1;

  v[p + 29][2] = 1;

  for(int i = 0 ; i < 30 ; i++) {
    if(0 < (k & (1 << i)))
      v[i * 2 + 4][p + i] = 1;
  }

  cout << nmax << '\n';
  for(int i = 1 ; i <= nmax ; i++) {
    for(int j = 1 ; j <= nmax ; j++)
      if(v[i][j] == 1 || v[j][i] == 1)
        cout << "Y";
      else
        cout << "N";
    cout << '\n';
  }
  return 0;
}