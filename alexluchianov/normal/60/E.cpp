#include <iostream>

using namespace std;

#define ll long long

int const nmax = 5;
int const kmax = 1000000;
int nums[5 + kmax];

int modulo;

struct Matrix{
  int n , m;
  int v[5 + nmax][5 + nmax];
  Matrix operator * (Matrix const &a) const{
    Matrix result = {0 , 0 , 0};

    result.n = n;
    result.m = a.m;

    for(int i = 1 ; i <= result.n ; i++){
      for(int j = 1 ; j <= result.m ; j++){
        for(int h = 1 ;h <= m ; h++) {
          result.v[i][j] += 1LL * v[i][h] * a.v[h][j] % modulo;

          if(modulo <= result.v[i][j])
            result.v[i][j] -= modulo;
          if(result.v[i][j] < 0)
            result.v[i][j] += modulo;

        }
      }
    }
    return result;
  }
};

Matrix lgpow(Matrix a , ll b){
  if(b == 1)
    return a;
  else {
    Matrix result = lgpow(a , b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

int getnewmax(int a , int b , ll steps){
  Matrix result = {0 , 0 , 0};
  result.n = result.m = 2;;
  result.v[1][1] = a;
  result.v[1][2] = b;
  Matrix exp = {0 , 0 , 0};
  exp.n = exp.m = 2;
  exp.v[1][1] = exp.v[1][2] = exp.v[2][1] = 1;
  if(steps == 0)
    return b;

  return (result * lgpow(exp , steps)).v[1][1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n , x , y ;
  cin >> n >> x >> y >> modulo;
  if(n == 1) {
    int a;
    cin >> a;
    cout << a % modulo;
    return 0;
  } else {
    ll sum = 0;
    for(int i = 1 ; i <= n ;i++){
      cin >> nums[i];
      nums[i] %= modulo;
      sum = (sum + nums[i]) % modulo;
    }
    Matrix init = {0 ,0 ,0};
    init.n = init.m = 3;
    init.v[1][1] = sum;
    init.v[1][2] = nums[1] % modulo;
    init.v[1][3] = nums[n] % modulo;

    //cout << sum << " " << nums[1] << " " << nums[n] << '\n';

    Matrix eps = {0 , 0 , 0};
    eps.n = eps.m = 3;
    eps.v[1][1] = 3;
    eps.v[2][1] = -1;
    eps.v[3][1] = -1;
    eps.v[2][2] = 1;
    eps.v[3][3] = 1;

    if(0 < x)
      init = init * lgpow(eps , x);

    //cout << ":";

    if(0 < x)
      init.v[1][3] = getnewmax(nums[n] , nums[n - 1] , x);
    //cout << init.v[1][1] << " " << init.v[1][2] <<  " " << init.v[1][3] << '\n';

    if(y == 0)
      cout << init.v[1][1] % modulo;
    else
      cout << (init * lgpow(eps , y)).v[1][1] % modulo;
  }
  return 0;
}