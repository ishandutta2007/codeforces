#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int v[1 + nmax], sum[1 + nmax];
int dp[1 + nmax][1 + nmax];
int sumdp[1 + nmax][1 + nmax];

int getsum(int x, int y){
  if(x <= 0)
    return sum[y];
  else
    return sum[y] - sum[x - 1];
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + v[i];

  for(int i = 0;i <= n; i++)
    for(int j = 0;j <= n; j++) {
      dp[i][j] = n;
      sumdp[i][j] = n;
    }

  dp[0][0] = 0;
  sumdp[0][0] = 0;

  for(int i = 1;i <= n; i++){
    int ptr = i;
    for(int j = i; 1 <= j; j--){
      while(1 <= ptr && getsum(ptr - 1, j - 1) <= getsum(j, i))
        ptr--;
      dp[j][i] = sumdp[ptr][j - 1] + (i - j);
    }

    sumdp[n][i] = dp[n][i];
    for(int j = n - 1; 0 <= j; j--)
      sumdp[j][i] = MIN(sumdp[j + 1][i], dp[j][i]);
  }
  cout << sumdp[1][n] << '\n';
  return 0;
}