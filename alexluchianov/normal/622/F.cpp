#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000000;
int const modulo = 1000000007;

class ModuloRing{
private:
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
public:
  int number;
  ModuloRing(int number_ = 0){
    if(number_ < 0)
      number = number_ % modulo + modulo;
    else
      number = number_ % modulo;
  }
  ModuloRing(ll number_ ){
    number = number_ % modulo;
  }

  ModuloRing operator + (ModuloRing const &a) const {
    return number + a.number;
  }
  ModuloRing operator - (ModuloRing const &a) const {
    return modulo + number - a.number;
  }
  ModuloRing operator * (ModuloRing const &a) const {
    return 1LL * number * a.number;
  }
  ModuloRing operator / (ModuloRing const &a){
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
};

ModuloRing lgpow(ModuloRing a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    ModuloRing result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

ModuloRing eval[5 + nmax];

int main()
{
  int n, k;
  cin >> n >> k;

  for(int i = 1;i <= k + 2; i++)
    eval[i] = eval[i - 1] + lgpow(i, k);
  if(n <= k + 2)
    cout << eval[n].number;
  else {
    ModuloRing result;
    ModuloRing prod(1);

    for(int i = 1;i <= k + 2; i++)
      prod = prod * (n - i);
    for(int i = 2;i <= k + 2; i++)
      prod = prod / (1 - i);
    result = result + eval[1] * prod / (n - 1);

    for(int i = 2;i <= k + 2; i++){
      prod = prod / (i - 1) * ((i - 1) - (k + 2));
      result = result + eval[i] * prod / (n - i);
    }
    cout << result.number;
  }
  return 0;
}