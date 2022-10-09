#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];
int seen[1 + nmax];

void dfs(int node, int color, bool &fatal){
  seen[node] = color;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(seen[to] == 0)
      dfs(to, 3 - color, fatal);
    else if(seen[to] == seen[node])
      fatal = true;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bool fatal = false;
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      dfs(i, 1, fatal);

  if(fatal == true)
    cout << -1;
  else {
    vector<int> sol1, sol2;
    for(int i = 1; i <= n; i++)
      if(seen[i] == 1)
        sol1.push_back(i);
      else
        sol2.push_back(i);
    cout << sol1.size() << '\n';
    for(int i = 0; i < sol1.size(); i++)
      cout << sol1[i] << " ";
    cout << '\n';
    cout << sol2.size() << '\n';
    for(int i = 0; i < sol2.size(); i++)
      cout << sol2[i] << " ";
    cout << '\n';
  }
  return 0;
}