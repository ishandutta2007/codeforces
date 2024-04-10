#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 30;
ll dp[1 + nmax][4][4];

int mv(int state, int ch, int chl, int chr){
  if(0 == (state & 2)){
    if(ch < chl)
      return -1;
    else if(chl < ch)
      state |= (1 << 1);
  }
  if(0 == (state & 1)){
    if(chr < ch)
      return -1;
    else if(ch < chr)
      state |= (1 << 0);
  }
  return state;
}


void solve(){
  int l, r;
  cin >> l >> r;
  for(int i = 0; i <= nmax; i++)
    for(int j = 0; j < 4; j++)
      for(int h = 0; h < 4; h++)
        dp[i][j][h] = 0;

  dp[nmax][0][0] = 1;

  for(int i = nmax - 1; 0 <= i; i--){
    int chl = (0 < ((1 << i) & l)), chr = (0 < ((1 << i) & r));

    for(int h = 0; h < 4; h++)
      for(int h2 = 0; h2 < 4; h2++)
        for(int ch1 = 0; ch1 < 2; ch1++)
          for(int ch2 = 0; ch2 < 2; ch2++) {
            int state1 = mv(h, ch1, chl, chr), state2 = mv(h2, ch2, chl, chr);
            if(0 <= state1 && 0 <= state2 && (0 == ch1 || 0 == ch2)) {
              dp[i][state1][state2] += dp[i + 1][h][h2];
            }
          }
  }

  ll result = 0;
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
      result += dp[0][i][j];
  cout << result << '\n';
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}
/*
1
2
1 1 0
RR
*/