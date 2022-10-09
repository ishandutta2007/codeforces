#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
int cost[1 + nmax], sz[1 + nmax], sol[1 + nmax];
bool failure = 0;
vector<int> g[1 + nmax];

void dfs2(int node, int target){
  if(target <= sol[node])
    sol[node]++;
  for(int h = 0; h < g[node].size(); h++)
    dfs2(g[node][h], target);
}

void dfs(int node, int bonus){
  sz[node] = 1;

  int start = bonus;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, bonus);
    sz[node] += sz[to];
    bonus += sz[to];
  }

  //cout << node << " " << bonus << '\n';

  if(sz[node] - 1 < cost[node])
    failure = 1;

  dfs2(node, start + cost[node]);
  sol[node] = start + cost[node];
}

int main()
{
  int n;
  cin >> n;
  int root = 1;
  for(int i = 1;i <= n; i++) {
    int parent;
    cin >> parent >> cost[i];
    if(parent == 0)
      root = i;
    else
      g[parent].push_back(i);
  }
  dfs(root, 1);

  if(failure == 0) {
    cout << "YES\n";
    for(int i = 1;i <= n; i++)
      cout << sol[i] << " ";
  } else {
    cout << "No";
  }
  return 0;
}