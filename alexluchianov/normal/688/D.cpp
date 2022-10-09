#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int const nmax = 40;

vector<int> primes;

bool v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 2 ; i * i <= k ; i++){
    if(k % i == 0){
      primes.push_back(1);
      while(k % i == 0){
        k /= i;
        primes.back() *= i;
      }
    }
  }
  if(1 < k)
    primes.push_back(k);

  for(int i = 1 ; i <= n ; i++){
    int a;
    cin >> a;
    for(int j = 0 ; j < primes.size() ; j++)
      if(a % primes[j] == 0 )
        v[j] = 1;
  }
  bool ok = 1;
  for(int j = 0 ; j < primes.size() ; j++)
    if(v[j] == 0)
      ok = 0;
  if(ok == 0)
    cout << "No";
  else
    cout << "Yes";

  return 0;
}