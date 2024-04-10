#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 30000;
int const rad = 300;
int gem[1 + nmax];
int dp[1 + nmax][5 + rad * 2];

int main()
{
  int n, d;
  cin >> n >> d;
  for(int i = 1;i <= n; i++){
    int x;
    cin >> x;
    gem[x]++;
  }

  for(int i = 1;i <= nmax; i++)
    for(int j = 0; j <= rad * 2 + 1; j++)
      dp[i][j] = -nmax;
  dp[d][rad] = gem[d];
  int result = gem[d];
  for(int i = d + 1;i <= nmax; i++)
    for(int j = 1; j <= rad * 2; j++){
      int last = i - d + (j - rad);
      if(1 <= last && last < i) {
        dp[i][j] = MAX(dp[i][j], MAX(dp[last][j - 1], MAX(dp[last][j], dp[last][j + 1])) + gem[i]);
        result = MAX(result, dp[i][j]);
      }
    }
  cout << result;
  return 0;
}