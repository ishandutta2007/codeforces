#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 1000;
int frec[1 + 2 * nmax];
int dp[1 + 2 * nmax];

int valid(int x){
  return 0 <= x && x <= nmax * 2;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int target, n;
  cin >> target >> n;
  queue<int> q;

  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    frec[val]++;
    if(frec[val] == 1){
      dp[nmax + val] = 1;
      q.push(nmax + val);
    }
  }
  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int i = 0;i <= 2 * nmax; i++)
      if(0 < frec[i]) {
        int x = node + i - target;
        if(valid(x) == 1 && dp[x] == 0){
          dp[x] = dp[node] + 1;
          q.push(x);
        }
      }
  }
  if(dp[target + nmax] == 0){
    cout << -1;
  } else
    cout << dp[target + nmax];
  return 0;
}