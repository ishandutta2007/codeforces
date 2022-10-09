#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];
map<pair<int,int>, int> edge;

int mult[1 + nmax], ptr = 0;
int n, m;

void dfs(int node){
  ++ptr;
  queue<int> q;
  vector<int> v;

  for(int i = 1;i <= n; i++)
    if(i != node)
      v.push_back(i);

  q.push(node);
  while(0 < q.size()){
    node = q.front();
    mult[node] = ptr;
    q.pop();
    vector<int> v2;
    for(int i = 0; i < v.size(); i++) {
      int to = v[i];
      if(edge[{node, to}] == 1)
        v2.push_back(to);
      else
        q.push(to);
    }
    v = v2;
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    edge[{x, y}] = edge[{y, x}] = 1;
  }
  for(int i = 1;i <= n; i++)
    if(mult[i] == 0)
      dfs(i);
  cout << ptr - 1;
  return 0;
}