#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  if(n <= m && n <= k)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}