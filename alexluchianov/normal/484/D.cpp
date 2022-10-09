#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
ll dp[1 + nmax][2];
int v[1 + nmax];

int cost(int x){
  return fabs(v[x] - v[x + 1]);
}

//can we take both edge x - 1 and x
bool cantake(int x){
  if(v[x - 1] < v[x] && v[x + 1] < v[x])
    return 0;
  if(v[x] < v[x - 1] && v[x] < v[x + 1])
    return 0;
  return 1;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  dp[1][1] = cost(1);
  for(int i = 2;i < n; i++)
    for(int h = 0; h < 2; h++)
      for(int h2 = 0; h2 < 2; h2++)
        if(h + h2 < 2 || cantake(i) == 1)
          dp[i][h2] = MAX(dp[i][h2], dp[i - 1][h] + h2 * cost(i));

  cout << MAX(dp[n - 1][0], dp[n - 1][1]);

  return 0;
}