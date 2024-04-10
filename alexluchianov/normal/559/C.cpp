#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 200000;
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
    number = number_ % modulo;
  }
  ModuloRing(ll number_) {
    number = number_ % modulo;
  }
  ModuloRing operator * (ModuloRing const &a) const{
    return 1LL * number * a.number;
  }
  ModuloRing operator + (ModuloRing const &a) const {
    return number + a.number;
  }
  ModuloRing operator - (ModuloRing const &a) const {
    return number - a.number + modulo;
  }
  ModuloRing operator / (ModuloRing const &a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
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
  return 0;
}

ModuloRing dp[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int l, r, n;
  cin >> l >> r >> n;
  vector<pair<int,int>> v;
  l--;r--;
  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    x--;y--;
    v.push_back({x, y});
  }
  v.push_back({l, r});
  sort(v.begin(), v.end());
  computefact();

  for(int i = 0;i < v.size(); i++) {
    dp[i] = comb(v[i].first + v[i].second, v[i].first);

    for(int j = 0; j < i; j++)
      if(v[j].first <= v[i].first && v[j].second <= v[i].second) {
        dp[i] = dp[i] - dp[j] * comb(v[i].first - v[j].first + v[i].second - v[j].second, v[i].first - v[j].first);
      }
  }
  cout << dp[v.size() - 1].number;
  return 0;
}