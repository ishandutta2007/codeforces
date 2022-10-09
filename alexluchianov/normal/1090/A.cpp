#include <iostream>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int sz[1 + nmax], valmax[1 + nmax];

int main()
{
  int n;
  cin >> n;
  int result = 0;
  for(int i = 1;i <= n; i++){
    cin >> sz[i];
    for(int j = 1;j <= sz[i]; j++){
      int a;
      cin >> a;
      valmax[i] = MAX(valmax[i], a);
    }
    result = MAX(result, valmax[i]);
  }
  ll result2 = 0;
  for(int i = 1; i <= n; i++)
    result2 += 1LL * (result - valmax[i]) * sz[i];
  cout << result2;
  return 0;
}