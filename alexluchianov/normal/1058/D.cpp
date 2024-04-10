#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
  ll n , m , k;
  cin >> n >> m >> k;
  if(0 < 1LL * n * m * 2 % k)
    cout << "NO\n";
  else {
    cout << "YES\n";
    cout << 0 << " " << 0 << '\n';

    ll area = (1LL * n * m * 2 / k) ;

    ll result = __gcd(area , n);

    if(result * 2 <= n && area / result % 2 == 0)
      result *= 2;

    cout << result << " " << 0 << '\n';
    cout << 0 << " " << area / result << '\n';


  }
  return 0;
}