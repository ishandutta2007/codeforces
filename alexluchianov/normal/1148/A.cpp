#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  ll a, b, c;
  cin >> a >> b >> c;
  ll val = min(a, b);
  a -= val;
  b -= val;
  c += val;
  cout << 2 * c + (0 < a) + (0 < b);

  return 0;
}