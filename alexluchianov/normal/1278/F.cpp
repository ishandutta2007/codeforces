#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int const modulo = 998244353;

class Zring{
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
  Zring(ll val = 0){
    number = val % modulo;
  }
  Zring operator + (Zring const oth){
    return number + oth.number;
  }
  Zring operator - (Zring const oth){
    return modulo + number - oth.number;
  }
  Zring operator * (Zring const oth){
    return 1LL * number * oth.number;
  }
  Zring operator / (Zring const oth){
    int x, y;
    gcd(oth.number, modulo, x, y);
    x = x % modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
};

Zring dp[1 + nmax][1 + nmax];

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  dp[1][1] = Zring(n) / m;

  for(int i = 2;i <= k; i++) {
    for(int j = 1;j <= i; j++){
      dp[i][j] = dp[i - 1][j] * j +
                 dp[i - 1][j - 1] * (n - (j - 1)) / m;
    }
  }

  //for(int i = 1;i <= k; i++)
  //  for(int j = 1;j <= i; j++)
  //    cout << i << " " << j << " " << dp[i][j].number << '\n';


  Zring result(0);
  for(int i = 1;i <= k; i++)
    result = result + dp[k][i];

  cout << (result).number;
  return 0;
}