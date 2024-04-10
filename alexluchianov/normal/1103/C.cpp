#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 250000;
int level[1 + nmax], father[1 + nmax], n, k;
vector<int> g[1 + nmax];

vector<vector<int>> sol;

void dfs(int node, int parent){

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }

  level[node] = level[parent] + 1;
  father[node] = parent;

  bool isleaf = true;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(level[to] == 0) {
      dfs(to, node);
      isleaf = false;
    }
  }
  if(isleaf == true){
    if(n <= 1LL * k * level[node]){
      cout << "PATH\n";
      cout << level[node] << '\n';
      int l = level[node];
      for(int i = 0; i < l; i++){
        cout << node << " ";
        node = father[node];
      }
      exit(0);
    } else {
      int node1 = g[node][0], node2 = g[node][1];
      vector<int> temp;
      if((level[node] - level[node1] + 1) % 3 != 0){
        while(node != node1){
          temp.push_back(node);
          node = father[node];
        }
        temp.push_back(node);
      } else if((level[node] - level[node2] + 1) % 3 != 0){
        while(node != node2){
          temp.push_back(node);
          node = father[node];
        }
        temp.push_back(node);
      } else {

        if(level[node1] < level[node2])
          swap(node1, node2);

        temp.push_back(node);
        while(node1 != node2){
          temp.push_back(node1);
          node1 = father[node1];
        }
        temp.push_back(node1);
      }
      sol.push_back(temp);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m >> k;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  cout << "CYCLES\n";
  for(int i = 0; i < k; i++){
    vector<int> temp = sol[i];
    cout << temp.size() << '\n';
    for(int j = 0; j < temp.size(); j++)
      cout << temp[j] << " ";
    cout << '\n';
  }
  return 0;
}