//#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<ll> sol;
  sol.push_back(0);

  ll n;
  cin >> n;
  ll n2 = n + 1;

  for(int i = 1 ; i * i <= n ; i++){
    if(n % i == 0){
      sol.push_back(1LL * (n - i + 2) * (n / i) / 2);

      int i2 = n / i;
      sol.push_back(1LL * (n - i2 + 2) * (n / i2) / 2);

    }
  }
  sort(sol.begin() , sol.end());
  for(int i = 1 ; i < sol.size() ; i++)
    if(sol[i] != sol[i - 1])
      cout << sol[i] << " ";

  return 0;
}