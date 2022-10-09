#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int lgpow(int a, int b, int modulo){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a % modulo;
  else{
    int result = lgpow(a, b / 2, modulo);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << (m + lgpow(3, n, m) - 1) % m;
  return 0;
}