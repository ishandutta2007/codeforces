#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))


int main()
{
  int n, k;
  cin >> n >> k;
  cout << (n + 1) + n + min(k - 1 + n - 1, n - k + n - 1);
  return 0;
}