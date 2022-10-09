#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;
vector<int> g[1 + nmax];
int seen[1 + nmax];

int dfs(int node, int parent){
  seen[node] = 1;

  int result = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      result += dfs(to, node);
  }
  return result + 1;
}

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else{
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  for(int i = 1;i < n; i++){
    int x, y, color;
    cin >> x >> y >> color;
    if(color == 0) {
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  int result = lgpow(n, k);
  for(int i = 1; i <= n; i++) {
    if(seen[i] == 0) {
      result -= lgpow(dfs(i, 0), k);
      if(result < 0)
        result += modulo;
    }
  }
  cout << result;

  return 0;
}