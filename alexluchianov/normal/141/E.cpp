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

int const nmax = 100000;
int const inf = 1000000000;

namespace Dsu{
  vector<int> mult;
  void initialize(int n){
    mult.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
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
    else
      mult[gala] = galb;
    return 1;
  }
}
int n, m;

struct Edge{
  int x;
  int y;
  int id;
  int cost;
  bool operator < (Edge const &a) const {
    return cost < a.cost;
  }
} edge[1 + nmax];

vector<int> sol;

int eval(int pos){
  Dsu::initialize(n);
  int result = 0;
  sol.clear();
  for(int i = m; pos < i; i--){
    if(Dsu::unite(edge[i].x, edge[i].y) == 1){
      result += edge[i].cost;
      sol.push_back(edge[i].id);
    }
  }
  for(int i = 1;i <= pos; i++)
    if(Dsu::unite(edge[i].x, edge[i].y) == 1){
      result += edge[i].cost;
      sol.push_back(edge[i].id);
    }

  if(sol.size() != n - 1)
    return inf;
  else
    return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  if(n % 2 == 0){
    cout << -1;
    return 0;
  }

  for(int i = 1;i <= m; i++){
    cin >> edge[i].x >> edge[i].y;
    char ch;
    cin >> ch;
    edge[i].id = i;
    if(ch == 'S')
      edge[i].cost = 1;
    else
      edge[i].cost = 0;
  }
  sort(edge + 1, edge + m + 1);
  int x = 1;
  for(int jump = (1 << 20); 0 < jump; jump /= 2){
    if(x + jump <= m && n / 2 <= eval(x + jump))
      x += jump;
  }

  if(eval(x) == n / 2) {
    cout << sol.size() << '\n';
    for(int i = 0; i < sol.size(); i++)
      cout << sol[i] << " ";
  } else
    cout << -1;
  return 0;
}