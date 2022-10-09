#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ld long double

int const nmax = 100;
ld v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  ld smax = 0, result = 0, prod = 1;
  for(int i = n; 1 <= i; i--){
    result = result * (1 - v[i]) + prod * v[i];
    prod = prod * (1 - v[i]);
    smax = max(smax, result);
  }
  cout << setprecision(15) << fixed << smax;

  return 0;
}