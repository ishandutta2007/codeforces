#include <iostream>

using namespace std;

int const nmax = 1500;
int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];

  int inversions = 0;
  for(int i = 1 ; i <= n ; i++)
    for(int j = 1 ; j < i ; j++)
      inversions += (v[i] < v[j]);
  inversions %= 2;
  int m;
  cin >> m;

  for(int i = 1 ; i <= m ;i++){
    int x , y;
    cin >> x >> y;
    x = y - x + 1;
    if(x * (x - 1) / 2 % 2 == 1)
      inversions = !inversions;
    if(inversions == 1)
      cout << "odd\n";
    else
      cout << "even\n";
  }
  return 0;
}