#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 250000;
int fact[1 + nmax];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, modulo;
  cin >> n >> modulo;
  fact[0] = 1;
  for(int i = 1;i <= n; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;

  ll result = 0, sum = 1;
  for(int i = n;1 <= i; i--){
    result += 1LL * (n - i + 1) * (n - i + 1) % modulo  * fact[i] % modulo * sum % modulo;
    sum = 1LL * sum * (n - i + 1) % modulo;
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}