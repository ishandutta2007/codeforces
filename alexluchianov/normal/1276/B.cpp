#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

namespace Dsu{
  vector<int> mult;
  vector<int> sz;
  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      sz[i] = 1;
    }
  }

  int jump(int gala){
    if(mult[gala] != gala)
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }

  void unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    if(gala != galb){
      sz[galb] += sz[gala];
      sz[gala] = 0;
      mult[gala] = galb;
    }
  }
}


void solve(){
  int n, m, start, stop;
  cin >> n >> m >> start >> stop;
  Dsu::initialize(n);
  vector<pair<int,int>> edge;
  vector<int> adiastop(1 + n), adiastart(1 + n);

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    if(x != start && x != stop && y != start && y != stop)
      Dsu::unite(x, y);
    else
      edge.push_back({x, y});
  }

  for(int i = 0; i < edge.size(); i++){
    int x = edge[i].first;
    int y = edge[i].second;
    if(x == start)
      adiastart[Dsu::jump(y)] = 1;
    else if(y == start)
      adiastart[Dsu::jump(x)] = 1;

    if(x == stop)
      adiastop[Dsu::jump(y)] = 1;
    else if(y == stop)
      adiastop[Dsu::jump(x)] = 1;
  }

  int totalstart = 0, totalstop = 0;

  for(int i = 1;i <= n; i++){
    int node = Dsu::jump(i);
    if(node == start || node == stop)
      continue;

    if(adiastart[node] == 1 && adiastop[node] == 0)
      totalstart++;
    else if(adiastart[node] == 0 && adiastop[node] == 1)
      totalstop++;
  }

  cout << 1LL * totalstart * totalstop << '\n';
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();

  return 0;
}