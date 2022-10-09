#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;
int seen[1 + nmax];
int p, k;

int cyclesize(int pos){
  seen[pos] = 1;
  int nxt = 1LL * pos * k % p;
  if(seen[nxt] == 0)
    return 1 + cyclesize(nxt);
  return 1;
}

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a % p;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % p;
    else
      return 1LL * result * result % p * a % p;
  }
}

int main()
{
  cin >> p >> k;
  int result = 1;
  if(k == 0){
    for(int i = 1; i < p; i++)
      result = 1LL * result * p % modulo;
    cout << result;
    return 0;
  }

  for(int i = 0; i < p; i++){
    if(seen[i] == 0) {
      int l = cyclesize(i);
      if(lgpow(k, l) == 1)
        result = 1LL * result * p % modulo;
    }
  }
  cout << result;
  return 0;
}