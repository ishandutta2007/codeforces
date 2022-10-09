#include <iostream>
#include <iomanip>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))
#define ld long double

ld lgpow(ld a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    ld result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}


int main()
{
  ld n, k, result = 0;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    result += i * (lgpow(i/n, k) - lgpow((i - 1) /n, k));
  }
  cout << setprecision(8) << fixed << result;

  return 0;
}