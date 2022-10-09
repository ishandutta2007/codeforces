#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[2][5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int n , s;
  cin >> n >> s;
  for(int i = 0 ; i < 2 ; i++)
    for(int j = 1 ; j <= n ; j++)
      cin >> v[i][j];
  if(s == 1)
    cout << "YES";
  else if(v[0][1] == 1){
    bool ok = 0;
    for(int j = s + 1 ; j <= n ; j++)
      ok |= (v[0][j] & v[1][j]);
    if(v[0][s] == 1){
      cout << "YES";
    } else if((v[1][s] & ok) == 1)
      cout << "YES";
    else
      cout << "NO";

  } else
    cout << "NO";
  return 0;
}