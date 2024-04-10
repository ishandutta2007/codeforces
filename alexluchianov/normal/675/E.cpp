#include <iostream>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const lgmax = 20;
int v[1 + nmax], lg[1 + nmax];
int rmq[1 + lgmax][1 + nmax];
ll dp[1 + nmax];

int getmax(int x, int y){
  int h = lg[y - x + 1];
  int rmqa = rmq[h][x], rmqb = rmq[h][y - (1 << h) + 1];
  if(v[rmqa] < v[rmqb])
    return rmqb;
  else
    return rmqa;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 2;i <= n; i++)
    lg[i] = lg[i / 2] + 1;

  for(int i = 1;i < n; i++)
    cin >> v[i];
  v[n] = n + 1;
  for(int i = 1;i <= n; i++)
    rmq[0][i] = i;

  for(int h = 1;h < lgmax; h++){
    for(int i = 1;i <= (n - (1 << h) + 1); i++){
      int rmqa = rmq[h - 1][i], rmqb = rmq[h - 1][i + (1 << (h - 1))];
      if(v[rmqa] < v[rmqb])
        rmq[h][i] = rmqb;
      else
        rmq[h][i] = rmqa;
    }
  }

  for(int i = n - 1; 1 <= i; i--){
    int pos = getmax(i + 1, v[i]);
    dp[i] = dp[pos] + (n - v[i]) + (pos - i);
  }
  ll result = 0;
  for(int i = 1;i <= n; i++)
    result += dp[i];
  cout << result;
  return 0;
}