#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 4000;
int const inf = 1000000000;
int const kmax = 800;

int sum[1 + nmax][1 + nmax];
int dp[1 + kmax][1 + nmax];
int sol[1 + kmax][1 + nmax];

int getsum(int x, int y, int x2, int y2){
  return sum[x2][y2] - sum[x - 1][y2] - sum[x2][y - 1] + sum[x - 1][y - 1];
}

void eval(int pos, int x, int y, int layer) {
  dp[layer][pos] = inf;
  for(int i = x; i <= y && i <= pos; i++){
    int result = dp[layer - 1][i - 1] + getsum(i, i, pos, pos);
    if(result < dp[layer][pos]){
      dp[layer][pos] = result;
      sol[layer][pos] = i;
    }
  }
}

void divide(int i, int j, int x, int y, int layer){
  if(i <= j){
    int mid = (i + j) / 2;
    eval(mid, x, y, layer);
    divide(i, mid - 1, x, sol[layer][mid], layer);
    divide(mid + 1, j, sol[layer][mid], y, layer);
  } else
    return ;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++) {
      char ch;
      cin >> ch;
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (ch - '0');
    }
  for(int i = 1;i <= n; i++)
    dp[1][i] = getsum(1, 1, i, i);

  for(int i = 2;i <= k; i++)
    divide(1, n, 1, n, i);
  cout << dp[k][n] / 2;
  return 0;
}