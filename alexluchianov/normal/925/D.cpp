#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int const nmax = 300000;
int const inf = 1000000000;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))

int n , m;
vector < int > g[5 + nmax];

int dist[5 + nmax];

bool bfs(int node){
  for(int i = 1 ; i <= n ;i++)
    dist[i] = inf;

  bool ok = 0;
  dist[node] = 0;

  queue < int > q;
  q.push(node);
  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0 ; h < g[node].size() ;h++){
      int to = g[node][h];
      if(to != 1 &&  dist[node] + 1 < dist[to]){
        dist[to] = dist[node] + 1;
        if(dist[to] == 2)
          ok = 1;
        q.push(to);
      }
    }
  }

  return ok;
}
int seen[5 + nmax];

bool checkifcomp(int node){
  if(seen[node] == 1)
    return 0;

  int sum = 0;
  int nodes = 1;
  queue < int > q;
  q.push(node);
  seen[node] = 1;

  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0 ; h < g[node].size() ;h++){
      int to = g[node][h];
      if(to != 1)
        sum ++;
      if(to != 1 && seen[to] == 0){
        seen[to] = 1;
        q.push(to);
        nodes++;
      }
    }
  }
  return (nodes * (nodes - 1)) == sum;
}

void printpath(int node){
  if(0 < dist[node])
    for(int h = 0 ; h < g[node].size() ;h++)
      if(dist[node] == dist[g[node][h]] + 1){
        printpath(g[node][h]);
        break;
      }
  cout << node  << " ";
}

int main()
{
  cin >> n >> m;
  for(int i = 1 ; i <= m ;i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bool ok = bfs(1);
  if(ok == 1){
    if(dist[n] < 4){
      cout << dist[n] << '\n';
      printpath(n);
      return 0;
    }
    for(int i = 1 ; i <= n ;i++)
      if(dist[i] == 2){
        cout << 4 << '\n';
        printpath(i);
        cout << 1 << " " << n << '\n';
        return 0;
      }
  }
  if(dist[n] < 5){
    cout << dist[n] << '\n';
    printpath(n);
    return 0;
  }

  for(int h = 0 ; h < g[1].size() ;h++){
    int to = g[1][h];
    if(checkifcomp(to) == 0){
      bfs(to);
      for(int i = 1 ; i <= n ;i++)
        if(dist[i] == 2){
          cout << 5 << '\n';
          cout << 1 << " ";
          printpath(i);
          cout << to << " " << n << '\n';
          return 0;
        }
    }
  }
  if(dist[n] < inf){
    cout << dist[n] << '\n';
    printpath(n);
  }
  cout << -1;
  return 0;
}