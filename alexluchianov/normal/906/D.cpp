#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
int const inf = 1000000000;

int v[1 + nmax];

int phi(int number){
  int result = 1;
  for(int i = 2;i * i <= number; i++){
    if(number % i == 0){
      result = result * (i - 1);
      number /= i;
      while(number % i == 0){
        result = result * i;
        number /= i;
      }
    }
  }
  if(1 < number)
    result = result * (number - 1);
  return result;
}
map<int,int> quick;

int lgpow(int a, int b, int modulo){
  if(b == 0)
    return 1 % modulo;
  else if(b == 1)
    return a % modulo;
  else {
    int result = lgpow(a, b / 2, modulo);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int lgpowsz(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpowsz(a, b / 2);
    ll newresult = 1LL * result * result;
    if(inf < newresult)
      return inf;
    if(b % 2 == 1)
      newresult = newresult * a;
    if(inf < newresult)
      return inf;
    return newresult;
  }
}

int evalbig(int from, int to, int step){
  if(v[from] == 1)
    return 1;
  else {
    if(step == 10)
      return inf;
    if(from < to)
      return lgpowsz(v[from], evalbig(from + 1, to, step + 1));
    else
      return v[from];
  }
}

int compute(int from, int to, int mod){
  if(mod == 1)
    return 0;
  else {
    if(from < to){
      int newmod = quick[mod];
      int result = compute(from + 1, to, newmod);

      int val = evalbig(from + 1, to, 0);
      if(val < newmod)
        return lgpow(v[from], result, mod);
      else
        return lgpow(v[from], result + newmod, mod);
    } else
      return v[from] % mod;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, orig, m;
  cin >> n >> m;
  orig = m;
  do {
    quick[m] = phi(m);
    m = quick[m];
  } while(1 < m);

  for(int i = 1;i <= n; i++)
    cin >> v[i];
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++){
    int x, y;
    cin >> x >> y;
    cout << compute(x, y, orig) << '\n';
  }
  return 0;
}