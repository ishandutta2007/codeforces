#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 400000;
int dp[1 + nmax];

int solve(ll from, ll to, int k){

  for(int i = 0; i <= to - from; i++)
    dp[i] = nmax;
  queue<ll> q;
  dp[to - from] = 0;
  q.push(to);

  while(0 < q.size()){
    ll node = q.front();
    q.pop();
    for(int i = 1;i <= k; i++){
      ll to;
      if(i == 1)
        to = node - 1;
      else
        to = node - node % i;
      if(from <= to && dp[node - from] + 1 < dp[to - from]){
        dp[to - from] = dp[node - from] + 1;
        q.push(to);
      }
    }
  }

  return dp[0];
}

int intervalsize(int k){
  int result = 1;
  for(int i = 1; i <= k; i++)
    result = result * i / __gcd(result, i);
  return result;
}

int main()
{
  ll a, b, k;
  cin >> a >> b >> k;
  swap(a, b);
  ll l = intervalsize(k);
  ll first, second;
  if(a % l == 0)
    first = a;
  else
    first = (a - a % l) + l;
  if(b % l == 0)
    second = b;
  else
    second = b - b % l;

  if(first <= second)
    cout << solve(a, first, k) + 1LL * solve(first, first + l, k) * ((second - first) / l) + solve(second, b, k) << '\n';
  else
    cout << solve(a, b, k);
  return 0;
}