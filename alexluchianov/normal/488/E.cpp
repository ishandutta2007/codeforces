#include <iostream>
#include <cmath>

using namespace std;

bool prime(int p){
  if(p == 1) //special case
    return 1;
  for(int i = 2;i * i <= p; i++)
    if(p % i == 0)
      return 0;
  return 1;
}

int modulo = 0;

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  int n;
  cin >> n;
  if(n == 1){
    cout << "YES\n";
    cout << 1;
    return 0;
  }
  if(prime(n) == 1) {
    cout << "YES\n";
    modulo = n;
    cout << 1 << '\n';
    for(int i = 2; i < n; i++)
      cout << 1LL * i * lgpow(i - 1, modulo - 2) % n << '\n';
    cout << n << '\n';

  } else if(n == 4){
    cout << "YES\n";
    cout << 1 << '\n' << 3 << '\n' << 2 << '\n' << 4 << '\n';
  } else
    cout << "NO";
  return 0;
}