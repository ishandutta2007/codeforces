#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll const inf = 1000000000000000000LL;

struct Edge{
  int to;
  int cost;
};
vector<Edge> g[1 + 5 * nmax];

int ptr = 0;
int id[1 + 5 * nmax], id2[1 + 5 * nmax];

void build(int node, int from, int to){
  id[node] = ++ptr;
  if(from < to){
    int mid = (from + to) / 2;
    build(node * 2, from, mid);
    build(node * 2 + 1, mid + 1, to);
    g[id[node]].push_back({id[node * 2], 0});
    g[id[node]].push_back({id[node * 2 + 1], 0});
  } else
    g[id[node]].push_back({from, 0});
}

void build2(int node, int from, int to){
  id2[node] = ++ptr;
  if(from < to){
    int mid = (from + to) / 2;
    build2(node * 2, from, mid);
    build2(node * 2 + 1, mid + 1, to);
    g[id2[node * 2]].push_back({id2[node], 0});
    g[id2[node * 2 + 1]].push_back({id2[node], 0});
  } else
    g[from].push_back({id2[node], 0});
}

void update(int node, int from, int to, int x, int y, Edge e){
  if(from == x && to == y)
    g[e.to].push_back({id[node], e.cost});
  else{
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, MIN(mid, y), e);
    if(mid + 1 <= y)
      update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, e);
  }
}

void update2(int node, int from, int to, int x, int y, Edge e){
  if(from == x && to == y) {
    g[id2[node]].push_back({e.to, e.cost});
  } else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update2(node * 2, from, mid, x, MIN(mid, y), e);
    if(mid + 1 <= y)
      update2(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, e);
  }
}

ll dp[1 + 5 * nmax];

struct Node{
  int node;
  ll val;
  bool operator < (Node const &a) const{
    return val > a.val;
  }
};

int main()
{
  int n, q, start;
  cin >> n >> q >> start;
  ptr = n;
  build(1, 1, n);
  build2(1, 1, n);
  for(int i = 1;i <= q; i++){
    int type;
    cin >> type;
    if(type == 1){
      int x, y, cost;
      cin >> x >> y >> cost;
      g[x].push_back({y, cost});
    } else if(type == 2){
      int x, l, r, cost;
      cin >> x >> l >> r >> cost;
      update(1, 1, n, l, r, {x, cost});
    } else {
      int x, l, r, cost;
      cin >> x >> l >> r >> cost;
      update2(1, 1, n, l, r, {x, cost});
    }
  }

  for(int i = 1;i <= ptr; i++)
    dp[i] = inf;
  priority_queue<Node> pq;
  pq.push({start, 0});
  dp[start] = 0;
  while(0 < pq.size()){
    int node = pq.top().node;
    if(dp[node] == pq.top().val){
      pq.pop();
      for(int h = 0; h < g[node].size(); h++){
        Edge e = g[node][h];
        if(dp[node] + e.cost < dp[e.to]){
          dp[e.to] = dp[node] + e.cost;
          pq.push({e.to, dp[e.to]});
        }
      }
    } else
      pq.pop();
  }

  for(int i = 1;i <= n; i++)
    if(dp[i] < inf)
      cout << dp[i] << " ";
    else
      cout << -1 << " ";
  return 0;
}