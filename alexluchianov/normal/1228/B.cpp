#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int const modulo = 1000000007;

int v[1 + nmax];
int v2[1 + nmax];
int mat[1 + nmax][1 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= m; i++)
    cin >> v2[i];
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      mat[i][j] = -1;

  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= v[i]; j++)
      if(mat[i][j] == 0)  {
        cout << 0;
        return 0;
      } else
        mat[i][j] = 1;
    if(v[i] < m) {
      if(mat[i][v[i] + 1] == 1) {
        cout << 0;
        return 0;
      } else
        mat[i][v[i] + 1] = 0;
    }
  }

  for(int i = 1;i <= m; i++) {
    for(int j = 1; j <= v2[i]; j++){
      if(mat[j][i] == 0){
        cout << 0;
        return 0;
      } else
        mat[j][i] = 1;
    }
    if(v2[i] < n) {
      if(mat[v2[i] + 1][i] == 1){
        cout << 0;
        return 0;
      } else
        mat[v2[i] + 1][i] = 0;
    }
  }

  int result = 1;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(mat[i][j] == -1)
        result = 1LL * result * 2 % modulo;
  cout << result;
  return 0;
}