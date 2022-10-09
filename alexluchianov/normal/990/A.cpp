#include <iostream>

using namespace std;
#define ll long long

int main()
{
  ll n , m ;
  int a , b;
  cin >> n >> m >> a >> b;
  cout << min(n % m * b , (m - n % m) * a );
  return 0;
}