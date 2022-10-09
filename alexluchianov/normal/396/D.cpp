#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

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
  ModuloRing(ll number_ = 0){
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
  ModuloRing operator / (ModuloRing const &a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x % modulo;
  }
};
class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n_){
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val){
    for(int x = pos; x <= n; x += x ^ (x & (x - 1)))
      aib[x] += val;
  }
  int query(int pos){
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};
int p[1 + nmax];
ModuloRing fact[1 + nmax], total[1 + nmax];

ModuloRing gauss(ModuloRing n){
  return n * (n + 1) / 2;
}

void computefact(int n){
  fact[0] = 1;
  for(int i = 1;i <= n; i++)
    fact[i] = fact[i - 1] * i;
  total[1] = 0;
  for(int i = 2;i <= n; i++)
    total[i] = total[i - 1] * i + fact[i - 1] * gauss(i - 1);
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> p[i];
  computefact(n);
  FenwickTree aib(n);
  for(int i = 1;i <= n; i++)
    aib.update(i, 1);
  ModuloRing result, sum = 0;

  for(int i = 1;i <= n; i++){
    int choices = aib.query(p[i] - 1);
    result = result + (sum * choices * fact[n - i]) + gauss(choices - 1) * fact[n - i] + (total[n - i] * choices);
    aib.update(p[i], -1);
    sum = sum + aib.query(p[i]);
  }
  cout << (result + sum).number;
  return 0;
}