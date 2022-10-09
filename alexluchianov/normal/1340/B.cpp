#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
string v[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[5 + nmax];
int dp[5 + nmax][5 + nmax];

int trans(string from, string to){
  int result = 0;
  for(int i = 0; i < from.size(); i++)
    if(to[i] < from[i])
      return 1 + nmax;
    else
      result += to[i] - from[i];
  return result;
}

int extract(int x, int y){
  if(y < 0)
    return 0;
  else
    return dp[x][y];
}

void print(int x, int y, int n){
  if(x == n + 1)
    return ;
  for(int h = 9; 0 <= h; h--){
    int cost = trans(s[x], v[h]);
    if(extract(x + 1, y - cost) == 1){
      cout << h;
      print(x + 1, y - cost, n);
      return ;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  dp[n + 1][0] = 1;
  for(int i = 1;i <= n; i++)
    cin >> s[i];
  for(int i = n; 1 <= i; i--){
    for(int h = 0; h <= 9; h++){
      int cost = trans(s[i], v[h]);
      for(int j = cost; j <= k; j++)
        dp[i][j] |= dp[i + 1][j - cost];
    }
  }
  if(dp[1][k] == 0)
    cout << -1;
  else
    print(1, k, n);
  return 0;
}