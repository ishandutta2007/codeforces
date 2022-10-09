#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const modulo = 998244353;
vector<int> g[1 + nmax];
int sz[1 + nmax];

int fact(int n){
  if(n == 0)
    return 1;
  else
    return 1LL * n * fact(n - 1) % modulo;
}

int dfs(int node, int parent){
  int result = 1;
  sz[node] = 1;

  int explored = 0;
  for(int h = 0;h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      result = 1LL * result * dfs(to, node) % modulo;
      sz[node] += sz[to];
      explored++;
    }
  }

  if(node == 1)
    result = 1LL * result * fact(explored) % modulo;
  else
    result = 1LL * result * fact(explored + 1) % modulo;
  return result;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cout << 1LL * n * dfs(1, 0) % modulo;
  return 0;
}