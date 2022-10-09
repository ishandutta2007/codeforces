#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500;
ll dp[1 + nmax], dp2[1 + nmax];

int main()
{
  /*
  ios::sync_with_stdio(0);
  cin.tie(0);
  */
  int n, k;
  cin >> n >> k;
  for(int i = 0; i <= k ; i++)
    dp[i] = -nmax;
  dp[0] = 0;
  int sum = 0;

  for(int i = 1;i <= n; i++){
    int a, b;
    cin >> a >> b;
    for(int j = 0; j < k; j++)
      dp2[j] = -nmax;

    for(int j = 0; j < k; j++){
      int oth = (sum + k - j) % k;
      for(int h = 0; h < k; h++){
        int oth2 = (k + a + b - h) % k;
        if(h <= a && oth2 <= b){
          dp2[(j + h) % k] = max(dp2[(j + h) % k], dp[j] + (j + h) / k + (oth + oth2) / k + (a + b - h - oth2) / k);
        }
      }
    }
    sum = (sum + a + b) % k;

    for(int j = 0; j < k; j++)
      dp[j] = dp2[j];
  }

  ll result = 0;
  for(int i = 0; i <= k; i++)
    result = max(result, dp[i]);
  cout << result;
  return 0;
}