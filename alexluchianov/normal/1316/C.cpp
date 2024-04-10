#include <iostream>

using namespace std;

int const nmax = 1000000;
int v[1 + nmax], v2[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, p;
  cin >> n >> m >> p;
  int result = 0;
  for(int i = 0;i < n; i++)
    cin >> v[i];
  for(int i = 0;i < m; i++)
    cin >> v2[i];
  for(int i = 0; i < n; i++)
    if(0 < v[i] % p) {
      result += i;
      break;
    }
  for(int i = 0; i < m; i++)
    if(0 < v2[i] % p){
      result += i;
      break;
    }
  cout << result;
  return 0;
}