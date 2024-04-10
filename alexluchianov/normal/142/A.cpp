#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const inf = 1000000000;
int const nmax = 1400;
ll divs[5 + nmax];
int divp = 0;

void decompose(ll n){
  for(int i = 1 ; i * i <= n ; i++){
    if(n % i == 0){
      divs[++divp] = i;
      if(i != n / i)
        divs[++divp] = n / i;
    }
  }
}

int main()
{
  ll n ;
  cin >> n;
  decompose(n);
  ll smin = 1LL * inf * inf;
  ll smax = 0;
  for(int i = 1 ; i <= divp ; i++){
    for(int j = 1 ; j <= divp ; j++){
      ll a = divs[i] , b = divs[j];
      if(n / a % b == 0){
        ll c = n / a / b;
        smin = MIN(smin , 1LL * (a + 1) * (b + 2) * (c + 2) - n);
        smax = MAX(smax , 1LL * (a + 1) * (b + 2) * (c + 2) - n);
      }
    }
  }
  cout << smin << " " << smax;
  return 0;
}