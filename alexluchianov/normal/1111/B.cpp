#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll v[5 + nmax];
ll sum[5 + nmax];


int main()
{
  ll n , m , k;
  cin >> n >> k >> m;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  sort(v + 1 , v + n + 1);

  for(int i = n ; 1 <= i ; i--)
    sum[i] = sum[i + 1] + v[i];

  double result = 0;

  /// eliminam pana in i -1
  for(int i = 1 ; i <= MIN(m + 1, n) ; i++) {
    double result2 = sum[i] + MIN(k * (n - i + 1) , m - i + 1);
    result = MAX(result , result2 / (n - i + 1));
  }
  cout << setprecision(8) << fixed << result;

  return 0;
}