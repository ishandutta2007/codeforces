#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 100000;
int edge[1 + nmax][3];

void normalize(int n){
  vector<int> temp;
  for(int i = 1;i < n; i++)
    temp.push_back(edge[i][2]);
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  map<int,int> code;
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;
  for(int i = 1;i < n; i++)
    edge[i][2] = code[edge[i][2]];
}

struct Edge{
  int x;
  int y;
  int id;
  int lvl;
  bool operator < (Edge const &a) const{
    return lvl > a.lvl;
  }
};

namespace Dsu{
  vector<int> mult;
  vector<int> sz;
  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
  }
  int jump(int gala){
    if(mult[gala] != gala)
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }
  void unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    sz[galb] += sz[gala];
    mult[gala] = galb;
  }
  int getsz(int gala){
    return sz[jump(gala)];
  }
};
vector<int> g[1 + nmax];
int level[1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}
vector<Edge> frec[1 + nmax];
int sol[1 + nmax][2];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i < n; i++) {
    cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    g[edge[i][0]].push_back(edge[i][1]);
    g[edge[i][1]].push_back(edge[i][0]);
  }
  dfs(1, 0);
  normalize(n);
  Dsu::initialize(n);
  for(int i = 1;i < n; i++) {
    int x = edge[i][0], y = edge[i][1];
    frec[edge[i][2]].push_back({x, y, i, max(level[x], level[y])});
  }
  for(int i = 1;i < n; i++){
    sort(frec[i].begin(), frec[i].end());
    for(int h = 0; h < frec[i].size(); h++){
      Edge e = frec[i][h];
      if(level[e.x] < level[e.y])
        sol[e.id][0] = Dsu::getsz(e.y);
      else
        sol[e.id][0] = Dsu::getsz(e.x);
      Dsu::unite(e.x, e.y);
    }
    for(int h = 0;h < frec[i].size(); h++){
      Edge e = frec[i][h];
      sol[e.id][1] = Dsu::getsz(e.x) - sol[e.id][0];
    }
  }
  vector<int> result;
  ll smax = 0;
  for(int i = 1;i < n; i++){
    ll smax2 = 1LL * sol[i][0] * sol[i][1];
    if(smax < smax2){
      smax = smax2;
      result.clear();
      result.push_back(i);
    } else if(smax == smax2)
      result.push_back(i);
  }
  cout << 2 * smax << " " << result.size() << '\n';
  for(int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  return 0;
}