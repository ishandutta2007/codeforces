#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 10000000;

ll gauss(int n){
  return 1LL * n * (n + 1) / 2;
}

int main()
{
  int m, b;
  cin >> m >> b;

  ll result = 0;
  for(int i = 0;i <= nmax; i++){
    int y;
    if(i % m == 0)
      y = -i / m + b;
    else
      y = -i / m - 1 + b;
    if(0 <= y)
      result = MAX(result, 1LL * (y + 1) * gauss(i) + 1LL * gauss(y) * (i + 1));
  }
  cout << result;
  return 0;
}