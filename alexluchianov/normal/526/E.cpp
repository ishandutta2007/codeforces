#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
ll const inf = 10000000000000000;

int const lgmax = 20;
ll v[5 + 2 * nmax];
ll sum[5 + nmax];
int far[5 + 2 * nmax], seen[5 + 2 * nmax];
int cost[5 + 2 * nmax], segment[1 + nmax];

int solve(int n){
  ll lim;
  cin >> lim;
  for(int i = 1;i <= n; i++) {
    far[i] = far[i - 1];
    while(far[i] <= n && sum[far[i]] - sum[i - 1] <= lim)
      far[i]++;
  }
  for(int i = n; 1 <= i; i--)
    if(far[i] <= n) {
      cost[i] = cost[far[i]];
      segment[i] = segment[far[i]] + 1;
      far[i] = far[far[i]];
    } else {
      cost[i] = sum[n] - sum[i - 1];
      segment[i] = 0;
    }
  int result = n;
  for(int i = 1;i <= n; i++){
    if(sum[i - 1] <= lim) {
      int l = 1 + segment[i] + (lim < (cost[i] + sum[i - 1]));
      result = min(result, l);
    }
  }

  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    v[n + i] = v[i];
  v[2 * n + 1] = inf;
  for(int i = 1;i <= 2 * n + 1; i++)
    sum[i] = sum[i - 1] + v[i];

  for(int i = 1; i <= q; i++)
    cout << solve(n) << '\n';
  return 0;
}