#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

int const nmax = 1000000;
int const lgmax = 22;
int v[1 + nmax];
int dp[1 + (1 << lgmax)];
pair<int,int> dp2[1 + (1 << lgmax)];

pair<int,int> combine(pair<int,int> a, pair<int,int> b){
  if(a.second == b.second)
    return {max(a.first, b.first), a.second};
  else if(a.second < b.second)
    return {max(a.second, b.first), b.second};
  else
    return {max(a.first, b.second), a.second};
}

bool eval(int target){
  for(int mask = 0; mask < (1 << lgmax); mask++){
    int mask2 = (target ^ (mask & target));
    if(dp[mask] < dp2[mask2].first)
      return 1;
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int mask = 0; mask < (1 << lgmax); mask++) {
    dp[mask] = n;
    dp2[mask] = {1, 1};
  }

  for(int i = 1;i <= n; i++) {
    dp[v[i]] = min(dp[v[i]], i);
    dp2[v[i]] = combine(dp2[v[i]], {1, i});
  }

  for(int i = lgmax - 1; 0 <= i; i--)
    for(int mask = 0; mask < (1 << lgmax); mask++)
      if(0 == (mask & (1 << i)))
        dp[mask] = min(dp[mask], dp[(mask ^ (1 << i))]);

  for(int i = lgmax - 1; 0 <= i; i--)
    for(int mask = 0; mask < (1 << lgmax); mask++)
      if(0 == (mask & (1 << i)))
        dp2[mask] = combine(dp2[mask], dp2[(mask ^ (1 << i))]);

  int result = 0;

  for(int i = lgmax - 1; 0 <= i; i--)
    if(eval(result + (1 << i)) == 1)
      result += (1 << i);
  cout << result;
  return 0;
}