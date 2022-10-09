#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const modulo = 1000000007;

vector<int> g[1 + nmax];
int dp[1 + nmax], dp2[1 + nmax];

void dfs(int node){
  dp[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to);
    dp[node] = 1LL * dp[node] * (dp[to] + 1) % modulo;
  }
}

void dfs2(int node){
  vector<int> pref(g[node].size());
  vector<int> suff(g[node].size());
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    pref[h] = suff[h] = (dp[to] + 1) % modulo;
  }
  for(int h = 1; h < g[node].size(); h++)
    pref[h] = 1LL * pref[h - 1] * pref[h] % modulo;
  for(int h = g[node].size() - 2; 0 <= h; h--)
    suff[h] = 1LL * suff[h] * suff[h + 1] % modulo;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    int result = dp2[node];
    if(0 < h)
      result = 1LL * result * pref[h - 1] % modulo;
    if(h + 1 < g[node].size())
      result = 1LL * result * suff[h + 1] % modulo;
    dp2[to] = (result + 1) % modulo;
    dfs2(to);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 2;i <= n; i++){
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  dfs(1);
  dp2[1] = 1;
  dfs2(1);
  for(int i = 1;i <= n; i++)
    cout << 1LL * dp[i] * dp2[i] % modulo << " " ;
  return 0;
}