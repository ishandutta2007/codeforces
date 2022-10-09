#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 500000;
ll const inf = 1000000000000000000;

int v[5 + nmax], cost[5 + nmax];
int pat[5 + nmax];

class FenwickTree{
  int n;
  vector<ll> aib;
public:
  FenwickTree(int n_){
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val){
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))) )
      aib[x] += val;
  }

  ll query(int x){
    ll result = 0;
    while(0 < x){
      result += aib[x];
      x = (x & (x - 1));
    }
    return result;
  }
};

int findtarget(int lim, int target){
  int x = 0;
  for(int jump = (1 << 20); 0 < jump; jump /= 2){
    if(x + jump <= lim && pat[x + jump] < target)
      x += jump;
  }
  return x + 1;
}

ll dp[5 + nmax];
ll bestsol[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    dp[i] = bestsol[i] = -inf;

  for(int i = 1;i <= n; i++)
    cin >> v[i];
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    cin >> cost[i];
    result += cost[i];
  }

  int m;
  cin >> m;
  for(int i = 1;i <= m; i++)
    cin >> pat[i];
  FenwickTree aib(1 + m);

  bestsol[m + 1] = 0;

  for(int i = n; 1 <= i; i--){
    int pos = findtarget(m, v[i]);
    if(pat[pos] == v[i]) {
      dp[pos] = max(dp[pos], cost[i] + bestsol[pos + 1] + aib.query(pos));
      bestsol[pos] = max(bestsol[pos], dp[pos] - aib.query(pos - 1));
    }
    if(0 <= cost[i])
      aib.update(pos, cost[i]);
  }

  if(dp[1] < -inf / 2)
    cout << "NO";
  else
    cout << "YES\n" << result - dp[1];

  return 0;
}