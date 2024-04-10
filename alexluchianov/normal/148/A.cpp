#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
char v[1 + nmax][1 + nmax];

int main()
{
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  int result = 0;
  for(int i = 1;i <= n; i++)
    if(i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0) {
      result++;
    }
  cout << result;
  return 0;
}