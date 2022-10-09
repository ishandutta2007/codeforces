#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 300000;
struct Edge{
  int x;
  int y;
  int cost;
  int id;
  bool operator < (Edge const &a) const{
    return cost < a.cost;
  }
};
Edge v[1 + nmax], v2[1 + nmax];

namespace Dsu{
  struct Update{
    int x;
    int y;
    int szx;
    int szy;
    int timestamp;
  };
  int odd;
  vector<int> mult;
  vector<int> sz;
  stack<Update> st;

  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
    odd = n;
  }
  int jump(int gala){
    if(gala != mult[gala])
      return jump(mult[gala]);
    return gala;
  }

  void unite(int gala, int galb, int timestamp){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    else {
      if(sz[galb] < sz[gala])
        swap(gala, galb);
      st.push({gala, galb, sz[gala], sz[galb], timestamp});
      if(sz[gala] % 2 == 1 && sz[galb] % 2 == 1)
        odd -= 2;
      sz[galb] += sz[gala];
      mult[gala] = galb;
    }
  }

  void erasetill(int timestamp){
    while(0 < st.size() && timestamp < st.top().timestamp){
      Update up = st.top();
      st.pop();
      mult[up.x] = up.x;
      mult[up.y] = up.y;
      sz[up.x] = up.szx;
      sz[up.y] = up.szy;
      if(sz[up.x] % 2 == 1 && sz[up.y] % 2 == 1)
        odd += 2;
    }
  }
}

int phase = 0;
int sol[1 + nmax];

void eval(int pos, int x, int y){
  ++phase;
  sol[pos] = y;
  for(int i = x; i <= y; i++){
    if(v2[i].id <= pos)
      Dsu::unite(v2[i].x, v2[i].y, phase);

    if(Dsu::odd == 0) {
      sol[pos] = i;
      break;
    }
  }
  Dsu::erasetill(phase - 1);
}

void addinterval(int pos1, int pos2, int lim, int timestamp){
  for(int i = pos1; i <= pos2; i++)
    if(v[i].cost <= lim)
      Dsu::unite(v[i].x, v[i].y, timestamp);
}

void addinterval2(int lim, int x, int y, int timestamp){
  for(int i = x;i <= y; i++)
    if(v2[i].id <= lim)
      Dsu::unite(v2[i].x, v2[i].y, timestamp);
}

void divide(int from, int to, int x, int y){
  if(from <= to){
    int curr = phase;

    int mid = (from + to) / 2;
    addinterval(from, mid, v2[x - 1].cost , ++phase);
    eval(mid, x, y);
    divide(mid + 1, to, x, sol[mid]);
    Dsu::erasetill(curr);
    addinterval2(from - 1, x, sol[mid] - 1, ++phase);
    divide(from, mid - 1, sol[mid], y);
    Dsu::erasetill(curr);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    cin >> v[i].x >> v[i].y >> v[i].cost;
    v[i].id = i;
  }
  v[m + 1] = {0, 0, 0, 0};
  Dsu::initialize(n);
  for(int i = 1; i <= m; i++)
    v2[i] = v[i];
  sort(v2 + 1, v2 + m + 1);
  divide(1, m, 1, m + 1);

  for(int i = 1;i <= m; i++)
    if(sol[i] == m + 1)
      cout << -1 << '\n';
    else
      cout << v2[sol[i]].cost << '\n';
  return 0;
}