#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll= long long;

int const nmax = 300000;
ll const maskmax = (1 << 30) - 1;

int dp[1 + nmax][3];

int mex(int a, int b, int c){
  for(int i = 0; i < 4; i++)
    if(i != a && i != b && i != c)
      return i;
  return 4;
}

int extract(int i, int j){
  if(i <= 0)
    return 0;
  else
    return dp[i][j];
}
map<int,int> frec;
int start, per;

int eval(ll x, int j){
  if(x <= start)
    return extract(x, j);
  else
    return extract(start + ((x - start) % per), j);
}

ll sold[1 + nmax];

void solve(){
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  int ptr = 0;
  ll mask = 0;
  frec.clear();
  while(true){
    ++ptr;
    dp[ptr][0] = mex(extract(ptr - x, 0), extract(ptr - y, 1), extract(ptr - z, 2));
    dp[ptr][1] = mex(extract(ptr - x, 0), -1, extract(ptr - z, 2));
    dp[ptr][2] = mex(extract(ptr - x, 0), extract(ptr - y, 1), -1);
    mask = (((mask<<6) + (dp[ptr][2]<<4) + (dp[ptr][1]<<2) + dp[ptr][0]) & maskmax);
    if(0 < frec[mask]){
      start = frec[mask];
      per = ptr - frec[mask];
      break;
    } else
      frec[mask] = ptr;
  }
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    cin >> sold[i];
    result ^= eval(sold[i], 0);
  }


  ll sol = 0;
  for(int i = 1; i <= n; i++){
    if((result ^ eval(sold[i], 0) ^ eval(sold[i] - x, 0)) == 0)
      sol++;
    if((result ^ eval(sold[i], 0) ^ eval(sold[i] - y, 1)) == 0)
      sol++;
    if((result ^ eval(sold[i], 0) ^ eval(sold[i] - z, 2)) == 0)
      sol++;
  }
  cout << sol << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++){
    solve();
  }
  return 0;
}