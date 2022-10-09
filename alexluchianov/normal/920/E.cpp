#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
map<pair<int,int>, int> edge;
int seen[1 + nmax];
int n, m;

int dfs(int node){
  queue<int> q;
  vector<int> v;
  q.push(node);

  for(int i = 1;i <= n; i++)
    if(i != node)
      v.push_back(i);

  int result = 0;
  while(0 < q.size()){
    node = q.front();
    q.pop();
    seen[node] = 1;
    result++;
    vector<int> v2;
    for(int i = 0; i < v.size(); i++){
      int to = v[i];
      if(edge[{node, to}] == 1)
        v2.push_back(to);
      else {
        q.push(to);
      }
    }
    v = v2;
  }
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    edge[{x, y}] = 1;
    edge[{y, x}] = 1;
  }
  vector<int> sol;
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      sol.push_back(dfs(i));
  sort(sol.begin(), sol.end());
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  return 0;
}
/*
7
1 2 5 3 4 6 7
011101
*/