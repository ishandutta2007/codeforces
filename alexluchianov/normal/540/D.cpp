#include <iostream>
#include <iomanip>

using namespace std;

int const nmax = 100;
double dp[5 + nmax][5 + nmax][5 + nmax];

int main()
{
  int r , s , p;
  cin >> r >> s >> p;
  dp[r][s][p] = 1;

  for(int i = r ; 0 <= i ; i--){
    for(int j = s ; 0 <= j ; j--){
      for(int h = p ; 0 <= h ; h--){
        double prob = i * j + j * h + i * h;
        if(0 < h && 0 < j)
          dp[i][j][h - 1] += dp[i][j][h] / prob * j * h;

        if(0 < j && 0 < i)
          dp[i][j - 1][h] += dp[i][j][h] / prob * j * i;

        if(0 < i && 0 < h)
          dp[i - 1][j][h] += dp[i][j][h] / prob * i * h;
      }
    }
  }
  double sum = 0;
  for(int i = 1 ; i <= r ; i++)
    sum += dp[i][0][0];
  cout << setprecision(10) << fixed ;
  cout << sum << " ";

  sum = 0;
  for(int i = 1 ; i <= s ; i++)
    sum += dp[0][i][0];
  cout << sum << " ";

  sum = 0;
  for(int i = 1 ; i <= p ; i++)
    sum += dp[0][0][i];
  cout << sum;
  return 0;
}