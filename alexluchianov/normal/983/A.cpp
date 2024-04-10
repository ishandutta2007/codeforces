#include <iostream>

using namespace std;

#define ll long long

ll gcd(ll a , ll b){
  while(a % b != 0){
    ll aux = a % b;
    a = b;
    b = aux;
  }
  return b;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++){
    ll a , b , d;
    cin >> a >> b >> d;
    ll div = gcd(a , b);
    a /= div;
    b /= div;
    while(true){
      div = gcd(b , d);
      if(1 == div)
        break;
      else {
        while(b % div == 0)
          b /= div;
        d = div;
      }
    }
    if(b == 1)
      cout << "Finite\n";
    else
      cout << "Infinite\n";
  }
  return 0;
}