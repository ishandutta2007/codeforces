#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

const int inf = 1000000000;

int t, n, s, d;
string a, b;
int dp[2][4], val[4];

void clear(int *dp) {
  dp[0] = dp[1] = dp[2] = dp[3] = -inf;
}

void upd(int &x, int y) {
  if (y > x) x = y;
}

int main()
{
  //freopen("test.in", "r", stdin);

  val[0] = 0;
  val[1] = 1;
  val[2] = 0;
  val[3] = 2;

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    cin >> n >> a >> b;
    
    s = 0; d = 1;
    clear(dp[s]);
    dp[s][0] = 0;

    for (int i = 0; i < n; i++) {
      clear(dp[d]);
      int curr = (a[i] - '0' + 1) | (b[i] - '0' + 1);

      for (int j = 0; j < 4; j++) 
        upd(dp[d][j | curr], dp[s][j]);

      for (int j = 1; j < 4; j++)
        upd(dp[d][0], dp[d][j] + val[j]);

      swap(s, d);
    }

    cout << dp[s][0] << '\n';
  }
  

  return 0;
}