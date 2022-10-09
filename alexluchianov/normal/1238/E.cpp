#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 20;
int const inf = 100000000;

char s[1 + nmax];
int cost[1 + sigma][1 + sigma];
int dp[(1 << sigma)];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++)
    cin >> s[i];
  for(int i = 2;i <= n;i++) {
    if(s[i - 1] != s[i]) {
      cost[s[i - 1] - 'a'][s[i] - 'a']++;
      cost[s[i] - 'a'][s[i - 1] - 'a']++;
    }
  }

  for(int mask = 0; mask < (1 << m); mask++)
    dp[mask] = inf;

  dp[0] = 0;
  for(int mask = 0; mask < (1 << m); mask++) {
    int pos = __builtin_popcount(mask);
    for(int i = 0; i < m; i++){
      if(0 < (mask & (1 << i))){
        int result = 0;
        int mask2 = mask ^ (1 << i);
        for(int j = 0; j < m; j++)
          if(0 < (mask2 & (1 << j)) ){
            result += pos * cost[j][i];
          } else
            result -= pos * cost[j][i];

        dp[mask] = MIN(dp[mask], dp[mask2] + result);
      }
    }
  }
  cout << dp[(1 << m) - 1];
  return 0;
}