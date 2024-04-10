#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000000;
int const modulo = 1000000007;

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}
int v[1 + nmax];

int solve(){
  int n, p;
  std::cin >> n >> p;
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::sort(v, v + n);

  int result = 0;
  int lastp = nmax;
  ll _count = 0;

  for(int i = n - 1; 0 <= i; i--){

    int d = lastp - v[i];
    if(p == 1 || _count == 0) {
      lastp = v[i];
    } else {
      if(d < 20){
        for(int i = 1; i <= d; i++){
          _count = _count * p;
          if(nmax < _count)
            _count = nmax;
        }
      } else 
        _count = nmax;
      lastp = v[i];
    }

    if(0 < _count){
      _count--;
      result = result - lgpow(p, v[i]);
      if(result < 0)
        result += modulo;
    } else {
      _count++;
      result = result + lgpow(p, v[i]);
      if(modulo <= result)
        result -= modulo;
    }
  }
  return result;
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
}