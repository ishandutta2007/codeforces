#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int type[1 + nmax], degree[1 + nmax];
ld chance[1 + nmax], sumnode[1 + nmax];

vector<int> g[1 + nmax][2];
vector<int> special[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> chance[i];
    chance[i] = 1 - chance[i];
  }
  vector<pair<int,int>> edge;
  for(int i = 1;i < n;i++){
    int x, y;
    cin >> x >> y;
    ++x;
    ++y;
    degree[x]++;
    degree[y]++;
    edge.push_back({x, y});
  }
  int rad = sqrt(n);
  ld sum = 0, sumedge = 0;

  for(int i = 1;i <= n; i++){
    if(degree[i] <= rad)
      type[i] = 0;
    else
      type[i] = 1;
    sum += chance[i];
  }

  for(int i = 0; i < edge.size(); i++){
    int x = edge[i].first, y = edge[i].second;
    sumedge += chance[x] * chance[y];
    if(type[x] == type[y]) {
      special[x].push_back(y);
      special[y].push_back(x);
    } else {
      g[x][type[y]].push_back(y);
      g[y][type[x]].push_back(x);
    }
  }

  for(int i = 1;i <= n;i++)
    if(type[i] == 0)
      for(int h = 0; h < g[i][1].size(); h++){
        int to = g[i][1][h];
        sumnode[to] += chance[i];
      }

  int q;
  cin >> q;

  for(int i = 1;i <= q; i++){
    int id;
    ld chc;
    cin >> id >> chc;
    id++;
    chc = 1 - chc;
    chc = chc - chance[id];
    sum += chc;
    chance[id] += chc;

    if(type[id] == 0)
      for(int h = 0; h < g[id][1].size(); h++){
        int to = g[id][1][h];
        sumnode[to] += chc;
        sumedge += chc * chance[to];
      }
    else
      sumedge += chc * sumnode[id];
    for(int h = 0;h < special[id].size(); h++)
      sumedge += chc * chance[special[id][h]];

    cout << setprecision(6) << fixed << sum - sumedge << '\n';
  }

  return 0;
}