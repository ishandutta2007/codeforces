#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;

int v[5 + nmax];

map<int,int> code;

void normalize(int n){
  vector<int> temp;
  for(int i = 1; i <= n; i++)
    temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;
  for(int i = 1;i <= n; i++)
    v[i] = code[v[i]];
}

int dp[5 + nmax][5 + nmax];
int leftcoef[5 + nmax], rightcoef[5 + nmax];

ll solve(int n, int color){
  vector<int> pos;
  int ptr = 0;
  pos.push_back(0);

  for(int i = 1;i <= n; i++){
    if(v[i] <= color)
      ++ptr;
    if(v[i] == color)
      pos.push_back(ptr);
  }
  for(int i = 0;i <= pos.size(); i++)
    for(int j = 0; j <= pos.size(); j++)
      dp[i][j] = nmax * nmax;
  dp[0][0] = 0;

  for(int i = 1; i < pos.size(); i++) {
    leftcoef[i] = pos[i] - i;
    rightcoef[i] = ptr - pos[i] - (pos.size() - 1 - i);
  }

  for(int i = 1; i < pos.size(); i++) {
    for(int j = 0; j <= i; j++){
      dp[i][j] = MIN(dp[i][j], dp[i - 1][j] + j + leftcoef[i]);
      if(0 < j)
        dp[i][j] = MIN(dp[i][j], dp[i - 1][j - 1] + rightcoef[i]);
    }
  }
  ll result = nmax * nmax;
  for(int i = 0; i <= pos.size(); i++)
    result = MIN(result, dp[pos.size() - 1][i]);
  return result;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    v[i] = fabs(v[i]);
  }
  normalize(n);

  ll result = 0;
  for(int i = n; 0 <= i; i--)
    result += solve(n, i);
  cout << result;
  return 0;
}