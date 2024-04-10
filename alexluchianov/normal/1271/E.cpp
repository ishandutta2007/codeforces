#include <iostream>

using namespace std;
using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int f(int x){
  if(x % 2 == 0)
    return x / 2;
  else
    return x - 1;
}

int const nmax = 10000;
int v[1 + nmax];

ll eval(ll x, ll n){
  if(x == 0)
    return n;
  ll from = x, to = x;
  if(x % 2 == 0)
    to = x + 1;

  ll result = 0;
  while(to <= n){
    result += (to - from + 1);
    from = from * 2;
    to = to * 2 + 1;
  }
  if(from <= n)
    result += (n - from + 1);
  return result;
}

int main()
{
  ll n, k;
  cin >> n >> k;
  ll xodd = 1, xeven = 0;
  for(ll jump = (1LL << 60); 1 < jump; jump /= 2){
    if(k <= eval(xodd + jump, n))
      xodd += jump;
  }
  for(ll jump = (1LL << 60); 1 < jump; jump /= 2){
    if(k <= eval(xeven + jump, n))
      xeven += jump;
  }
  cout << MAX(xodd, xeven);
  return 0;
}