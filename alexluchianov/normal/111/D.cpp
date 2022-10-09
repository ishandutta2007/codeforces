#include <iostream>

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
  ModuloRing(int _ = 0){
    number = _ % modulo;
  }
  ModuloRing(ll _){
    number = _ % modulo;
  }
  ModuloRing operator + (ModuloRing const &a) const{
    return number + a.number;
  }
  ModuloRing operator * (ModuloRing const &a) const{
    return 1LL * number * a.number;
  }
  ModuloRing operator / (ModuloRing const &a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
  ModuloRing operator - (ModuloRing const &a) const{
    return modulo + number - a.number;
  }

};

ModuloRing fact[1 + nmax];

void computefact(){
  fact[0] = 1;
  for(int i = 1;i <= nmax; i++)
    fact[i] = fact[i - 1] * i;
}

ModuloRing comb(int n, int k){
  if(0 <= k && k <= n)
    return fact[n] / fact[k] / fact[n - k];
  else
    return 0;
}

ModuloRing lgpow(ModuloRing a, ll b){
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

ModuloRing dp[1 + nmax];

int main()
{
  computefact();
  int n, m, k;
  cin >> n >> m >> k;
  if(m == 1) {
    cout << lgpow(k, n).number << '\n';
    return 0;
  }
  dp[1] = 1;
  for(int i = 2;i <= n; i++){
    dp[i] = lgpow(i, n);
    for(int j = 1; j < i; j++)
      dp[i] = dp[i] - comb(i, j) * dp[j];
  }
  ModuloRing result;
  for(int i = 0;i <= n; i++)
    for(int j = 0; j <= n; j++)
      if(i + 2 * j <= k){
        result = result + comb(k, i) * comb(k - i, j) * comb(k - i - j, j) * dp[i + j] * dp[i + j] * lgpow(i, 1LL * n * (m - 2));
      }
  cout << result.number;
  return 0;
}