#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int v[1 + nmax][2];
int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i][0] >> v[i][1];
  int k;
  cin >> k;
  int result = 0;
  for(int i = 1;i <= n; i++)
    if(k <= v[i][1])
      result++;
  cout << result;
  return 0;
}