#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

using ll = long long;

void solve(ll x, ll y){
  if(x == 1 && y == 1)
    return ;
  if(x == 1){
    cout << y - 1 << 'B';
    return ;
  } else if(y == 1){
    cout << x - 1 << 'A';
    return ;
  }

  if(x < y){
    cout << y / x << 'B';
    solve(x, y % x);
  } else {
    cout << x / y << 'A';
    solve(x % y, y);
  }
}

int main()
{
  ll a, b;
  cin >> a >> b;
  if(1 < __gcd(a, b))
    cout << "Impossible\n";
  else
    solve(a, b);
  return 0;
}