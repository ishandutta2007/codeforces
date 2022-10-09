#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int v[1 + nmax], frec[1 + nmax];
int dp[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    frec[v[i]] = i;

  int result = 0;
  for(int i = n; 1 <= i; i--){
    dp[i] = 1;
    for(int j = 2 * v[i]; j <= nmax; j += v[i])
      dp[i] = MAX(dp[i], 1 + dp[frec[j]]);
    result = MAX(result, dp[i]);
  }
  cout << result;
  return 0;
}