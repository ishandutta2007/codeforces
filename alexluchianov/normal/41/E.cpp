#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n;
  cin >> n;
  int n2 = n / 2;
  cout << n2 * (n - n2) << '\n';
  for(int i = 1;i <= n2; i++)
    for(int j = n2 + 1; j <= n; j++)
      cout << i << " " << j << '\n';

  return 0;
}