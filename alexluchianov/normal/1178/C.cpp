#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo = 998244353;

int main()
{
  int n, m;
  cin >> n >> m;
  ll result = 1;
  for(int i = 1;i <= n; i++)
    result = result * 2 % modulo;
  for(int i = 1;i <= m; i++)
    result = result * 2 % modulo;
  cout << result;
  return 0;
}