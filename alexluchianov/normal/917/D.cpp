#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 100;
int const modulo = 1000000007;

vector<int> g[1 + nmax];
int dp[1 + nmax][1 + nmax][1 + nmax], sz[1 + nmax];
int n;
void gcd(int a, int b, int &x, int &y){
  if(b == 0){
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}
int inv[1 + nmax];

void computeinv(){
  inv[0] = 1;
  for(int i = 1;i <= nmax; i++){
    int x, y;
    gcd(i, modulo,x , y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    inv[i] = x;
  }
}
int dp2[1 + nmax][1 + nmax];

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  sz[node] = 1;
  dp[node][0][1] = n;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
    for(int i = 0; i <= sz[node] + sz[to]; i++)
      for(int j = 0; j <= sz[node] + sz[to]; j++)
        dp2[i][j] = 0;

    for(int i = 0; i < sz[node]; i++) {
      for(int h1 = 1; h1 <= sz[node]; h1++) {
        for(int j = 0; j < sz[to]; j++)
          for(int h2 = 1; h2 <= sz[to]; h2++) {
            dp2[i + j][h1] += 1LL * dp[node][i][h1] * dp[to][j][h2] % modulo;
            if(modulo <= dp2[i + j][h1])
              dp2[i + j][h1] -= modulo;

            dp2[i + j + 1][h1 + h2] += 1LL * dp[node][i][h1] * dp[to][j][h2] % modulo * inv[h1] % modulo * inv[h2] % modulo * (h1 + h2) % modulo * inv[n] % modulo;
            if(modulo <= dp2[i + j + 1][h1 + h2])
              dp2[i + j + 1][h1 + h2] -= modulo;
          }
      }
    }
    sz[node] += sz[to];
    for(int i = 0;i < sz[node]; i++)
      for(int j = 1;j <= sz[node]; j++)
        dp[node][i][j] = dp2[i][j];
  }
}
int sol[1 + nmax];
int fact[1 + nmax];

int comb(int n, int k){
  if(0 <= k && k <= n) {
    int result = 1LL * fact[n - k] * fact[k] % modulo;
    int x, y;
    gcd(result, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;

    return 1LL * fact[n] * x % modulo;
  } else
    return 0;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  computeinv();
  fact[0] = 1;
  for(int i = 1;i <= n; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;


  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for(int i = n - 1; 0 <= i; i--){
    for(int j = 1; j <= n; j++) {
      sol[i] += dp[1][i][j];
      if(modulo <= sol[i])
        sol[i] -= modulo;
    }
    for(int j = i + 1; j <= n; j++) {
      sol[i] -= 1LL * sol[j] * comb(j, i) % modulo;
      if(sol[i] < 0)
        sol[i] += modulo;
    }
  }

  for(int i = 0;i <= n - 1; i++)
    cout << 1LL * sol[i] * inv[n] % modulo * inv[n] % modulo << " ";
  return 0;
}