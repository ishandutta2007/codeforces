#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;

void apply(vector<int> &dp, bool modded){
  for(int bit = 1; bit < nmax; bit = bit * 10){
    for(int i = nmax - 1; 1 <= i; i--) {
      if(i / bit % 10 < 9) {
        dp[i] += dp[i + bit];
        if(modded == 1 && modulo <= dp[i])
          dp[i] -= modulo;
      }
    }
  }
}

vector<int> sum(1 + nmax), sum2(1 + nmax), sz(1 + nmax);

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}
vector<int> sol(1 + nmax), sol2(1 + nmax);
vector<int> bitlist[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    sum[val] += val;
    if(modulo <= sum[val])
      sum[val] -= modulo;
    sum2[val] += 1LL * val * val % modulo;
    if(modulo <= sum2[val])
      sum2[val] -= modulo;
    sz[val]++;
  }

  for(int mask = 0; mask < (1 << 6); mask++) {
    int bit = 1;
    for(int j = 0; j < 6; j++, bit *= 10)
      if(0 < ((1 << j) & mask))
        bitlist[mask].push_back(bit);
  }


  apply(sum, 1);
  apply(sum2, 1);
  apply(sz, 0);
  for(int i = 0; i < nmax; i++){
    ll result = (1LL * sum[i] * sum[i] - sum2[i]) % modulo, result2 = sum2[i];
    if(result < 0)
      result += modulo;

    if(2 <= sz[i])
      result = 1LL * result * lgpow(2, sz[i] - 2) % modulo;
    if(1 <= sz[i])
      result2 = 1LL * result2 * lgpow(2, sz[i] - 1) % modulo;

    sol[i] = (result + result2) % modulo;
  }

  ll total = 0;

  for(int i = 0; i < nmax; i++){
    ll result = 0;
    for(int mask = 0; mask < (1 << 6); mask++){
      bool invalid = 0;
      int bit = 1;
      ll val = i;
      for(int j = 0; j < bitlist[mask].size(); j++) {
        bit = bitlist[mask][j];
        if(i / bit % 10 == 9)
          invalid = 1;
        else
          val += bit;
      }

      if(invalid == 0){
        if(bitlist[mask].size() % 2 == 0) {
          result += sol[val];
          if(modulo <= result)
            result -= modulo;
        } else {
          result -= sol[val];
          if(result < 0)
            result += modulo;
        }
      }
    }
    total ^= (i * result);
  }
  cout << total;
  return 0;
}