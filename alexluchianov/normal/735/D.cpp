#include <iostream>

using namespace std;

#define ll long long

bool isprime(int n){
  for(int i = 2 ; i * i <= n ; i++)
    if(n % i == 0)
      return 0;
  return 1;
}

int main()
{
  int n;
  cin >> n;
  if(isprime(n) == 1)
    cout << 1;
  else if(n % 2 == 0)
    cout << 2;
  else if(isprime(n - 2) == 1)
    cout << 2;
  else
    cout << 3;
  return 0;
}