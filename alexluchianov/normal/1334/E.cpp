#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 120;
int const modulo = 998244353;
vector<ll> primes;
ll v[1 + nmax][2];

void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int inv(int number){
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

int fact(int number){
  int result = 1;
  for(int i = 1;i <= number; i++)
    result = 1LL * result * i % modulo;
  return result;
}

int solve(){
  ll number1, number2;
  cin >> number1 >> number2;

  for(int i = 0;i <= nmax; i++)
    v[i][0] = v[i][1] = 0;

  for(int i = 0; i < primes.size(); i++)
    while(number1 % primes[i] == 0) {
      v[i][0]++;
      number1 /= primes[i];
    }

  for(int i = 0; i < primes.size(); i++)
    while(number2 % primes[i] == 0) {
      v[i][1]++;
      number2 /= primes[i];
    }

  int sum = 0, sum2 = 0;
  int result = 1;
  for(int i = 0; i < primes.size(); i++){
    int val = v[i][0] - min(v[i][1], v[i][0]);
    result = 1LL * result * fact(val) % modulo;
    sum += val;
    val = v[i][1] - min(v[i][1], v[i][0]);
    sum2 += val;
    result = 1LL * result * fact(val) % modulo;
  }
  return 1LL * inv(result) * fact(sum) % modulo * fact(sum2) % modulo;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll number;
  cin >> number;
  for(int i = 2; 1LL * i * i <= number; i++){
    if(number % i == 0){
      primes.push_back(i);
      while(number % i == 0)
        number /= i;
    }
  }
  if(1 < number)
    primes.push_back(number);

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++)
    cout << solve() << '\n';
  return 0;
}