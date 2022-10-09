#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Path{
  int x;
  int y;
  int z;
  bool operator < (Path const &a) const {
    if(x != a.x)
      return x < a.x;
    else if(y != a.y)
      return y < a.y;
    else
      return z < a.z;
  }
};
set<Path> invalid;
int const nmax = 3000;
int dist[1 + nmax][1 + nmax];
int last[1 + nmax][1 + nmax];

set<int> g[1 + nmax];

void print(int x, int y){
  if(0 < x)
    print(last[x][y], x);
  cout << y << " " ;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
  }
  for(int i = 1;i <= k; i++){
    int x, y, z;
    cin >> x >> y >> z;
    invalid.insert({x, y, z});
  }
  queue<pair<int,int> > q;
  q.push({0, 1});
  dist[0][1] = 0;
  last[0][1] = 0;
  while(0 < q.size()){
    pair<int,int> p = q.front();
    q.pop();
    int node = p.second;
    set<int>::iterator it = g[node].begin();
    while(it != g[node].end()){
      int to = *it;
      if(invalid.find({p.first, node, to}) == invalid.end()){
        dist[node][to] = dist[p.first][node] + 1;
        last[node][to] = p.first;
        q.push({node, to});
        g[node].erase(it++);
      } else
        it++;
    }
  }

  int result = -1, id = 0;
  for(int i = 1; i <= n; i++)
    if(0 < dist[i][n] && (result == -1 || dist[i][n] < result)){
      result = dist[i][n];
      id = i;
    }
  cout << result << '\n';
  if(0 < result)
    print(id, n);
  return 0;
}