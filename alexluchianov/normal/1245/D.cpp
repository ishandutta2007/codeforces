#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
int const modulo = 1000000007;

struct Point{
  int x;
  int y;
} v[1 + nmax];
int cost[1 + nmax];
int k[1 + nmax];

struct Edge{
  int x;
  int y;
  ll cost;
  bool operator < (Edge const &a) const{
    return cost < a.cost;
  }
};

int mult[1 + nmax];
int jump(int a){
  if(a != mult[a])
    mult[a] = jump(mult[a]);
  return mult[a];
}

void unite(int gala, int galb){
  gala = jump(gala);
  galb = jump(galb);
  if(gala != galb)
    mult[gala] = galb;
}

int dist(Point a, Point b){
  return fabs(a.x - b.x) + fabs(a.y - b.y);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i <= n; i++)
    mult[i] = i;

  for(int i = 1;i <= n; i++)
    cin >> v[i].x >> v[i].y;
  for(int i = 1;i <= n; i++)
    cin >> cost[i];
  for(int i = 1;i <= n; i++)
    cin >> k[i];
  vector<Edge> edge;
  for(int i = 1;i <= n; i++)
    edge.push_back({0, i, cost[i]});
  for(int i = 1;i <= n; i++)
    for(int j = i + 1;j <= n; j++) {
      edge.push_back({i, j, 1LL * dist(v[i], v[j]) * (k[i] + k[j])});
    }
  sort(edge.begin(), edge.end());
  ll result = 0;

  vector<int> sol;
  vector<pair<int,int>> sol2;

  for(int i = 0; i < edge.size(); i++){
    Edge e = edge[i];
    if(jump(e.x) != jump(e.y)){
      unite(e.x, e.y);
      result += e.cost;
      if(e.x == 0)
        sol.push_back(e.y);
      else if(e.y == 0)
        sol.push_back(e.x);
      else
        sol2.push_back({e.x, e.y});
    }
  }
  cout << result << '\n';
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  cout << '\n';
  cout << sol2.size() << '\n';
  for(int i = 0; i < sol2.size(); i++)
    cout << sol2[i].first << " " << sol2[i].second << '\n';
  return 0;
}
/*
1
2
1 1 0
RR
*/