#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50;
int l[1 + nmax], r[1 + nmax];

int main()
{
  int n, x;
  cin >> n >> x;
  for(int i = 1;i <= n; i++)
    cin >> l[i] >> r[i];
  int result = 0;
  for(int i = 1; i <= n; i++) {
    result += (l[i] - 1 - r[i - 1]) % x;
    result += (r[i] - l[i] + 1);
   }
  cout << result;
  return 0;
}