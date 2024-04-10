#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 1000000;

int combine(char op, int x, int y){
  if(op == 'A')
    return (x & y);
  else if(op == 'O')
    return (x | y);
  else if(op == 'X')
    return (x ^ y);
  else if(op == 'a')
    return !(x & y);
  else if(op == 'o')
    return !(x | y);
  else if(op == 'x')
    return !(x ^ y);
}

int coresp(char op, int x){
  if(combine(op, x, 0) == 0 && combine(op, x, 1) == 0)
    return 2;
  else if(combine(op, x, 0) == 0)
    return 0;
  else if(combine(op, x, 1) == 0)
    return 1;
  else
    return -1; ///nothing is valid
}

int pow3[5 + nmax];
int dp[1 + nmax];

int b2tob3(int bits, int number){
  int result = 0;
  for(int i = 0; i < bits; i++)
    if(0 < ((1 << i) & number))
      result += pow3[i];
  return result;
}

int getbit(int mask, int pos){
  return mask / pow3[pos] % 3;
}

string word;

ll bkt(int pos, int mask, int mask2){
  if(pos == word.size())
    return 1LL * dp[mask] * dp[mask2];
  else{
    ll result = 0;
    int bit = coresp(word[pos], 0);
    if(0 <= bit)
      result += bkt(pos + 1, mask, mask2 + pow3[pos] * bit);
    int bit2 = coresp(word[pos], 1);
    if(0 <= bit2)
      result += bkt(pos + 1, mask + pow3[pos], mask2 + pow3[pos] * bit2);
    return result;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int bits, n, m;
  cin >> bits >> n >> m;
  pow3[0] = 1;
  for(int i = 1;i <= bits; i++)
    pow3[i] = pow3[i - 1] * 3;

  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    int mask = b2tob3(bits, val);
    dp[b2tob3(bits, val)]++;
  }

  for(int mask = 0; mask < pow3[bits]; mask++){
    for(int i = 0; i < bits; i++)
      if(getbit(mask, i) == 2) {
        dp[mask] = dp[mask - pow3[i]] + dp[mask - pow3[i] * 2];
        break;
      }

  }

  for(int i = 1;i <= m; i++){
    cin >> word;
    reverse(word.begin(), word.end());

    cout << bkt(0, 0, 0) << '\n';
  }
  return 0;
}