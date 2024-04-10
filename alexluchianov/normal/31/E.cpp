#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 40;
ll pow10[5 + nmax];

void precompute(){
  pow10[0] = 1;
  for(int i = 1 ; i <= 18 ; i++)
    pow10[i] = pow10[i - 1] * 10;
}
char v[5 + nmax];

ll dp[5 + nmax][5 + nmax];

void computedp(int n){
  for(int h = 1 ; h <= n * 2 ;h++){
    for(int i = 0 ; i <= h ; i++){
      int j = h - i;
      if(i <= n && j <= n){
        if(0 < i)
          dp[i][j] = MAX(dp[i][j] , dp[i - 1][j] + (v[h] - '0') * pow10[n - i]);
        if(0 < j)
          dp[i][j] = MAX(dp[i][j] , dp[i][j - 1] + (v[h] - '0') * pow10[n - j]);
      }
    }
  }
}
void explore(int i ,int j ,int n){
  if(i == 0 && j == 0)
    return;
  if(0 < i)
    if(dp[i][j] == dp[i - 1][j] + (v[i + j] - '0') * pow10[n - i]) {
      explore(i - 1 , j , n);
      cout << "H";
      return ;
    }

  explore(i , j - 1 , n);
  cout << "M";
}

int main()
{
  precompute();

  int n;
  cin >> n;
  for(int i = 1 ; i <= n * 2; i++)
    cin >> v[i];

  computedp(n);
  explore(n , n , n);

  return 0;
}