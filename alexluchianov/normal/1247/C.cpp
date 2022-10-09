#include <iostream>

using namespace std;

using ll = long long;

int main()
{
  ll n, p;
  cin >> n >> p;
  for(int i = 1;i <= 40; i++){
    ll val = n - i * p;
    if(i <= val && __builtin_popcount(val) <= i) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}