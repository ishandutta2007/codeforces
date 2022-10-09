#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int const sqrtmax = sqrt(nmax);
int w[1 + nmax];
ll sol[1 + nmax];

vector<pair<int,int>> layer[1 + sqrtmax];
ll dp[1 + nmax];

void solvelayer(int n, int x){
  for(int i = n; 1 <= i; i--){
    dp[i] = w[i];
    if(i + x <= n)
      dp[i] += dp[i + x];
  }
  for(int h = 0; h < layer[x].size(); h++)
    sol[layer[x][h].second] = dp[layer[x][h].first];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, lim;
  cin >> n;
  lim = sqrt(n);
  for(int i = 1;i <= n; i++)
    cin >> w[i];
  cin >> m;
  for(int i = 1;i <= m; i++){
    int a, b;
    cin >> a >> b;
    if(b <= lim)
      layer[b].push_back({a, i});
    else {
      ll result = 0;
      while(a <= n){
        result += w[a];
        a += b;
      }
      sol[i] = result;
    }
  }

  for(int i = 1;i <= lim; i++)
    solvelayer(n, i);

  for(int i = 1; i <= m; i++)
    cout << sol[i] << '\n';
  return 0;
}