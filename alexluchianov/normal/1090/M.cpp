#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  int result = 1, sum = 1;
  for(int i = 2;i <= n; i++){
    if(v[i - 1] != v[i])
      sum++;
    else
      sum = 1;
    result = MAX(result, sum);
  }
  cout << result;
  return 0;
}