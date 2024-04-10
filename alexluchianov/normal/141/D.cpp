#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
map<int,int> code;
struct ramp{
  int to;
  int cost;
  int id;
};
vector<ramp> g[1 + nmax];
int dist[1 + nmax], last[1 + nmax], id[1 + nmax];

vector<int> sol;

void solve(int node){
  if(node == 1)
    return ;
  solve(last[node]);
  if(id[node] != 0)
    sol.push_back(id[node]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, lim;
  cin >> n >> lim;

  code[0] = 1;
  code[lim] = 2;
  vector<int> temp;

  temp.push_back(0);
  temp.push_back(lim);

  int ptr = 2;

  for(int i = 1;i <= n; i++){
    int x, d, t, p;
    cin >> x >> d >> t >> p;
    int start = x - p, stop = x + d, cost = p + t;
    if(0 <= start){
      if(code[start] == 0) {
        code[start] = ++ptr;
        temp.push_back(start);
      }
      if(code[stop] == 0) {
        code[stop] = ++ptr;
        temp.push_back(stop);
      }
      start = code[start];
      stop = code[stop];
      g[start].push_back({stop, cost, i});
    }
  }

  sort(temp.begin(), temp.end());
  for(int i = 1; i < temp.size(); i++){
    int p1 = temp[i - 1], p2 = temp[i];
    g[code[p1]].push_back({code[p2], p2 - p1, 0});
    g[code[p2]].push_back({code[p1], p2 - p1, 0});
  }

  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  for(int i = 1;i <= temp.size(); i++)
    dist[i] = -1;
  dist[1] = 0;
  pq.push({0, 1});
  while(0 < pq.size()){
    int node = pq.top().second, cost = pq.top().first;
    pq.pop();
    if(cost == dist[node]){
      for(int h = 0; h < g[node].size(); h++){
        int to = g[node][h].to;
        if(dist[to] == -1 || dist[node] + g[node][h].cost < dist[to]){
          dist[to] = dist[node] + g[node][h].cost;
          last[to] = node;
          id[to] = g[node][h].id;
          pq.push({dist[to], to});
        }
      }
    }
  }
  cout << dist[2] << '\n';
  solve(2);
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  return 0;
}