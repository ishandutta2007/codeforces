#include <iostream>

using namespace std;

using ll = long long;

ll f(ll a, ll b){
  if(a < b)
    swap(a, b);
  if(a == 0 || b == 0)
    return 0;
  else
    return f(a % b, b) + a / b;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << f(a, b);

  return 0;
}