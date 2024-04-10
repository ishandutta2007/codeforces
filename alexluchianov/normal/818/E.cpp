#include <iostream>

using namespace std;

int const nmax = 100000;
int v[20][5 + nmax];

int getdp(int x ,int y , int k){
  if(0 <= v[x][y])
    return v[x][y];
  else
    v[x][y] = 1ll * getdp(x - 1 , y , k) * getdp(x - 1 , y + (1 << x) / 2 , k)   % k;
  return v[x][y];

}

int solve(int x , int lim , int k){
  int result = 1;
  for(int step = 20 ; 0 <= step ; step--){
    if(x + (1 << step) - 1 <= lim){
      if(1LL * result * getdp(step , x , k) % k != 0){
        result = 1LL * result * getdp(step , x , k) % k;
        x += (1 << step);
      }
    }
  }
  return lim - x + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n , k;
  cin >> n >> k;

  for(int i = 0 ; i < 20 ; i++)
    for(int j = 1 ; j <= n ; j++)
      v[i][j] = -1;

  for(int i = 1 ; i <= n ;i++) {
    cin >> v[0][i];
    v[0][i] %= k;
  }
  long long result = 0;
  for(int i = 1 ; i <= n ; i++){
    result += solve(i , n , k);
  }
  cout << result;

  return 0;
}