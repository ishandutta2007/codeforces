#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo = 1000000007;
std::map<char,int> frec;

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b/ 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    char ch;
    std::cin >> ch;
    frec[ch]++;
  }
  int smax = 0, scount = 0;
  char cand[4] = {'A', 'C', 'G', 'T'};
  for(int i = 0; i < 4; i++) {
    int val = frec[cand[i]];
    if(smax < val) {
      smax = val;
      scount = 1;
    } else if(smax == val)
      scount++;
  }
  std::cout << lgpow(scount, n);
  return 0;
}