#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int const nmax = 200000;
int v[1 + nmax];

int normalize(int m){
  vector<int> temp;
  map<int,int> code;
  for(int i = 1;i <= m; i++)
    if(0 <= v[i])
      temp.push_back(v[i]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;
  for(int i = 1;i <= m; i++)
    if(0 <= v[i])
      v[i] = code[v[i]];
  return temp.size();
}

vector<int> g[1 + nmax];
int indegree[1 + nmax];

void addEdge(int x, int y){
  g[x].push_back(y);
  indegree[y]++;
}

vector<int> sol;
int seen[1 + nmax], in_stack[1 + nmax];

void dfs(int node, bool &fail){
  seen[node] = 1;
  in_stack[node] = 1;
  for(int h = 0;h < g[node].size(); h++){
    int to = g[node][h];
    if(seen[to] == 0)
      dfs(to, fail);
    else if(in_stack[to] == 1){
      fail = true;
      return ;
    }
  }
  in_stack[node] = 0;
  sol.push_back(node);
}

void topogicalsort(int n, bool &fail){
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      dfs(i, fail);
  reverse(sol.begin(), sol.end());
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int ptr = m;

  for(int i = 1;i <= n; i++){
    for(int j = 1;j <= m; j++)
      cin >> v[j];
    int sz = normalize(m);
    for(int j = 1;j <= m; j++)
      if(-1 == v[j])
        continue;
      else {
        if(v[j] < sz)
          addEdge(j, ptr + v[j] + 1);
        addEdge(ptr + v[j], j);
      }
    ptr += sz;
  }

  bool fail = false;
  topogicalsort(ptr, fail);

  if(fail == true)
    cout << -1;
  else {
    for(int i = 0; i < sol.size(); i++)
      if(sol[i] <= m)
        cout << sol[i] << " ";
  }
  return 0;
}