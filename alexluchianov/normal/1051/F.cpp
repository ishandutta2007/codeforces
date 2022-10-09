#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

struct Edge{
  int from;
  int to;
  int cost;
};

vector < Edge > g[5 + nmax];
vector < Edge > g2[5 + nmax];

int jump[5 + nmax];

int n , m;


int jumpx(int node){
  //cout << node << " " << jump(node) << '\n';
  if(node != jump[node])
    jump[node] = jumpx(jump[node]);
  return jump[node];
}

void unite(int x , int y){
  x = jumpx(x);
  y = jumpx(y);
  if(x != y)
    jump[x] = y;
}

int special[5 + nmax];
int level[5 + nmax];
ll cost[5 + nmax];
int pos[5 + nmax];

int lg[5 + nmax];

int specp = 0;

int euler[5 + 4 * nmax];
int parentp[5 + 4 * nmax];

int eulerp = 0;

void computeall(int node , int parent){
  euler[++eulerp] = node;
  pos[node] = eulerp;
  //cout << node << " " << parent << '\n';

  for(int h = 0 ; h < g[node].size() ;h++){
    Edge e = g[node][h];
    if(e.to != parent){
      level[e.to] = level[node] + 1;
      parentp[node] = parent;
      cost[e.to] = cost[node] + e.cost;


      computeall(e.to , node);

      euler[++eulerp] = node;
    }
  }
}

int rmq[25][5 + nmax * 4];

void computermq(){
  for(int i = 1 ; i <= eulerp  ; i++){
    rmq[0][i] = euler[i];
  }
  for(int h = 1 ; h <= 20 ; h++){
    for(int i = 1 ; i <= eulerp - (1 << h) + 1 ; i++){
      int nodex = rmq[h - 1][i];
      int nodey = rmq[h - 1][i + (1 << (h - 1))];
      if(level[nodex] > level[nodey])
        rmq[h][i] = nodey;
      else
        rmq[h][i] = nodex;
    }
  }
}

int computelca(int x , int y){
  x = pos[x];
  y = pos[y];
  if(y < x)
    swap(x , y);
  int h = lg[y - x + 1];

  int nodex = rmq[h][x];
  int nodey = rmq[h][y - (1 << h) + 1];
  if(level[nodex] > level[nodey])
    return nodey;
  else
    return nodex;
}

vector<ll> dist[5 + nmax];

void computedist(int node){
  queue<int> q;
  if(0 < dist[node].size())
    return ;

  dist[node].resize(n + 5);
  for(int i = 1 ; i <= n ; i++)
    dist[node][i] = -1;

  dist[node][node] = 0;
  q.push(node);
  int init = node;

  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0 ; h < g2[node].size() ; h++){
      Edge e = g2[node][h];
      if(dist[init][e.to] == -1 || dist[init][node] + e.cost < dist[init][e.to]){
        dist[init][e.to] = dist[init][node] + e.cost;
        q.push(e.to);
      }
    }
  }
}

int main()
{
  for(int i = 2 ; i <= nmax ; i++)
    lg[i] = lg[i / 2] + 1;

  cin >> n >> m;
  for(int i = 1 ; i <= n ; i++)
    jump[i] = i;

  for(int i = 1 ; i <= m ; i++){
    int x , y , cost;
    cin >> x >> y >> cost;
    if(jumpx(x) != jumpx(y)){
      unite(x , y);
      g[x].push_back({x , y , cost});
      g[y].push_back({y , x , cost});
    } else {
      special[++specp] = x;
      special[++specp] = y;
    }

    g2[x].push_back({x , y , cost});
    g2[y].push_back({y , x , cost});
  }
  //cout << ":";
  computeall(1 , 0);
  //cout << "|";
  computermq();
  //cout << ":";

  for(int i = 1 ; i <= specp ; i++)
    computedist(special[i]);

  int querys;
  cin >> querys;

  for(int i = 1 ;i <= querys ; i++){
    int x , y;
    cin >> x >> y;
    //cout <<  computelca(x , y) << " " << cost[x] << " " <<  cost[y] << " " <<  cost[computelca(x , y)] << " "  << '\n';
    ll result = cost[x] + cost[y] - cost[computelca(x , y)] * 2;

    for(int h = 1 ; h <= specp ; h++){
      ll result2 = dist[special[h]][x] + dist[special[h]][y];
      result = MIN(result , result2);
    }
    cout << result << '\n';
  }
  return 0;
}
/*
7 6
1 2 4
1 3 4
2 4 2
2 5 2
3 6 1
3 7 1

4
5 6
1 4
7 5
5 4
*/