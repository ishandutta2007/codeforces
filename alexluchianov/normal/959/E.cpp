#include <iostream>

using namespace std;

#define ll long long

ll sol(ll n){
  int p = 0;

  while((1LL << (p + 1)) <= n)
    p++;
  if(n <= 1)
    return n;
  else if((n & (n + 1)) == 0){ ///power of 2
    return sol(n / 2) * 2 + (1LL << p);
  } else {
    return sol(n ^ (1LL << p)) + sol((1LL << p) - 1) + (1LL << p);
  }
}

int main()
{
  ll k;
  cin >> k;
  k--;
  cout << sol(k);

  return 0;
}