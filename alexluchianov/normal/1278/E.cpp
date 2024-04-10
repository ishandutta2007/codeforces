#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
std::vector<int> g[1 + nmax];

int sz[1 + nmax], ptr = 0;
int l[1 + nmax], r[1 + nmax], start[1 + nmax], stop[1 + nmax];
int addon[1 + nmax];

void dfs(int node, int parent){
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  start[node] = ++ptr;
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
    sz[node] += sz[to];
  }
  stop[node] = ptr;

  r[start[node]] = sz[node] * 2;
  l[start[node]] = sz[node] * 2 - 1 - g[node].size();

  int displaced = 0;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    r[start[to]] = (sz[node] * 2 - h - 1) - displaced;
    addon[start[to]] += displaced;
    addon[stop[to] + 1] -= displaced;
    displaced += sz[to] * 2 - 1;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for(int i = 1;i <= n;i ++) {
    addon[i] += addon[i - 1];
    l[i] += addon[i];
    r[i] += addon[i];
  }
  for(int i = 1;i <= n; i++)
    cout << l[start[i]] << " " << r[start[i]] << '\n';
  return 0;
}