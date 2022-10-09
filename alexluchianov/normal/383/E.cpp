#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 10000;
int const sigma = 24;

int extract(string s){
  int result = 0;
  for(int i = 0; i < s.size(); i++)
    result |= (1 << (s[i] - 'a'));
  return result;
}

int dp[1 + (1 << sigma)];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    string s;
    cin >> s;
    dp[extract(s)]++;
  }
  for(int i = 0; i < sigma; i++)
    for(int mask = (1 << sigma) - 1;0 <= mask; mask--)
      if(mask & (1 << i))
        dp[mask] += dp[mask ^ (1 << i)];
  int result = 0;
  for(int mask = 0; mask < (1 << sigma); mask++)
    result ^= (n - dp[mask]) * (n - dp[mask]);
  cout << result;
  return 0;
}