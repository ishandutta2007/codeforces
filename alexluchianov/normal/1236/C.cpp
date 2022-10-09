#include <iostream>

using namespace std;
#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300;
int const modulo = 1000000007;

int v[1 + nmax][1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int op = 0;
  for(int i = 1;i <= n; i++){
    if(i % 2 == 1)
      for(int j = 1;j <= n; j++)
        v[j][i] = ++op;
    else
      for(int j = n; 1 <= j; j--)
        v[j][i] = ++op;
  }
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= n; j++)
      cout << v[i][j] << " ";
    cout << '\n';
  }
  cout << '\n';
  return 0;
}