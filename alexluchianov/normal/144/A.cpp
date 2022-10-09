#include <iostream>

using namespace std;

int const nmax = 100;
int v[1 + nmax];

int main()
{
  int n;
  cin >> n;
  int smax = 1, smin = 1;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    if(v[smax] < v[i])
      smax = i;
    if(v[smin] >= v[i])
      smin = i;
  }
  if(smax < smin)
    cout << smax - 1 + n - smin << '\n';
  else {
    cout << smax - 1 + n - smin - 1<< '\n';
  }
  return 0;
}