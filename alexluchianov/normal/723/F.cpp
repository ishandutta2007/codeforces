#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 200000;

namespace Dsu{
  vector<int> mult;
  vector<int> sz;
  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n;i++) {
      mult[i] = i;
      sz[i] = 1;
    }
  }
  int jump(int gala){
    if(gala != mult[gala])
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }

  bool unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return 0;
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    mult[gala] = galb;
    sz[galb] += sz[gala];
    return 1;
  }
}

int rep[1 + nmax], rep2[1 + nmax];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  vector<pair<int,int>> edges;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
  }
  Dsu::initialize(n);
  int s, t, costs, costt;
  cin >> s >> t >> costs >> costt;

  vector<pair<int,int>> sol;

  for(int i = 0; i < edges.size(); i++){
    int x = edges[i].first;
    int y = edges[i].second;
    if(x != s && x != t && y != s && y != t){
      if(Dsu::unite(x, y) == 1)
        sol.push_back(edges[i]);
    }
  }
  for(int i = 0; i < edges.size(); i++){
    int x = edges[i].first;
    int y = edges[i].second;
    if(y == s || y == t)
      swap(x, y);
    if(x == s && y != t)
      rep[Dsu::jump(y)] = y;
    if(x == t && y != s)
      rep2[Dsu::jump(y)] = y;
  }

  for(int i = 1;i <= n; i++) {
    if(0 < rep[i] && 0 == rep2[i]) {
      if(Dsu::unite(rep[i], s) == 1) {
        sol.push_back({rep[i], s});
        costs--;
      }
    } if(0 == rep[i] && 0 < rep2[i]) {
      if(Dsu::unite(rep2[i], t) == 1) {
        sol.push_back({rep2[i], t});
        costt--;
      }
    }
  }

  for(int i = 1;i <= n; i++){
    if(0 < rep[i] && 0 < rep2[i]){
      if(Dsu::jump(s) != Dsu::jump(t)){
        if(Dsu::unite(rep2[i], t) == 1) {
          sol.push_back({rep2[i], t});
          costt--;
        }
        if(Dsu::unite(rep[i], s) == 1) {
          sol.push_back({rep[i], s});
          costs--;
        }
      }
      if(costs < costt){
        if(Dsu::unite(rep2[i], t) == 1) {
          sol.push_back({rep2[i], t});
          costt--;
        }
      } else {
        if(Dsu::unite(rep[i], s) == 1) {
          sol.push_back({rep[i], s});
          costs--;
        }
      }
    }
  }

  if(Dsu::unite(s, t) == 1) {
    sol.push_back({s, t});
    costs--;
    costt--;
  }

  if(0 <= costs && 0 <= costt){
    cout << "Yes\n";
    for(int i = 0; i < sol.size(); i++)
      cout << sol[i].first << " " << sol[i].second << '\n';
  } else
    cout << "No\n";

  return 0;
}