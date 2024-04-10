#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
vector<int> g[1 + nmax];
int deg[1 + nmax];

int dfs(int node, int parent, int &result){
  int scount = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      scount += dfs(to, node, result);
  }
  if(2 <= scount){
    result--;
    return 0;
  } else if(1 == scount)
    return 1;
  else{
    result++;
    return 1;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x, y;
  cin >> n >> x >> y;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++;
    deg[y]++;

  }
  if(n == 2){
    cout << x;
  } else {
    int result = 0;
    dfs(1, 0, result);
    if(y < x) {
      for(int i = 1;i <= n; i++)
        if(deg[i] == n - 1) {
          cout << 1LL * y * (n - 2) + x;
          return 0;
        }
      cout << 1LL * y * (n - 1);
    } else
      cout << 1LL * x * (n - 1 - (result - 1)) + 1LL * (result - 1) * y;
  }
  return 0;
}