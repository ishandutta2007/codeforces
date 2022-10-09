#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];
int far[1 + nmax], depth[1 + nmax], frec[1 + nmax];

void dfs(int node, int parent){
  far[node] = parent;
  depth[node] = depth[parent] + 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = 1;
  while(g[root].size() == 1)
    root++;
  dfs(root, 0);
  int result1 = 1, result2 = 0;
  int des = -1;
  for(int i = 1;i <= n; i++){
    if(g[i].size() == 1){
      if(des != -1 && des != depth[i] % 2)
        result1 = 3;
      des = depth[i] % 2;

      if(frec[far[i]] == 1)
        result2++;
      frec[far[i]] = 1;
    }
  }
  cout << result1 << " " << n - 1 - result2 << '\n';
  return 0;
}