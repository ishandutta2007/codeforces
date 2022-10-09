#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2500;
int v[1 + nmax][1 + nmax];
struct Edge{
  int x;
  int y;
  int cost;
  bool operator < (Edge const &a) const{
    return cost < a.cost;
  }
};
vector<Edge> edge;
int mult[1 + nmax], sz[1 + nmax];

int jump(int a){
  if(a != mult[a])
    mult[a] = jump(mult[a]);
  return mult[a];
}

void unite(int gala, int galb){
  gala = jump(gala);
  galb = jump(galb);
  if(gala != galb){
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    sz[galb] += sz[gala];
    mult[gala] = galb;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    mult[i] = i;
    sz[i] = 1;
  }

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= n; j++)
      cin >> v[i][j];
  for(int i = 1;i <= n; i++)
    if(0 < v[i][i]){
      cout << "NOT MAGIC\n";
      return 0;
    }
  for(int i = 1;i <= n; i++)
    for(int j = i + 1;j <= n; j++)
      if(v[i][j] != v[j][i]) {
        cout << "NOT MAGIC\n";
        return 0;
      }
  for(int i = 1;i <= n; i++)
    for(int j = i + 1;j <= n; j++)
      edge.push_back({i, j, v[i][j]});
  sort(edge.begin(), edge.end());
  int ptr = 0;

  for(int i = 0; i < edge.size(); i++){
    while(ptr < edge.size() && edge[ptr].cost < edge[i].cost){
      unite(edge[ptr].x, edge[ptr].y);
      ptr++;
    }
    if(jump(edge[i].x) == jump(edge[i].y)){
      cout << "NOT MAGIC\n";
      return 0;
    }
  }
  cout << "MAGIC";
  return 0;
}