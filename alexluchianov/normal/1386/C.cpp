#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax][2];

namespace Dsu{
  struct Data{
    int x;
    int y;
    int szx;
    int szy;
    int verdict;
  };
  int curr_verdict;
  std::vector<int> mult, sz, weight;
  void initialize(int n) {
    mult.resize(1 + n);
    sz.resize(1 + n);
    weight.resize(1 + n);
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      sz[i] = 1;
    }
    curr_verdict = 0;
  }
  int jump(int a) {
    if(a != mult[a])
       return jump(mult[a]);
     return a;
  }
  
  int modifier(int a) {
    if(mult[a] == a)
      return 0;
    else
      return modifier(mult[a]) ^ weight[a];
  }
  std::stack<Data> st;

  void unite(int x, int y) {
    int cost = modifier(x) ^ modifier(y);
    x = jump(x);
    y = jump(y);
    if(x == y) {
      if(cost == 0) {
        st.push({0, 0, 0, 0, curr_verdict});         
        curr_verdict = 1;
      } else {
        st.push({0, 0, 0, 0, curr_verdict});
      }
    } else {
      if(sz[y] < sz[x])
        std::swap(x, y);
      st.push({x, y, sz[x], sz[y], curr_verdict});
      sz[y] += sz[x];
      mult[x] = y;
      weight[x] = 1 ^ cost;
    }
  }
  void undo() {
    if(0 < st.size()) {
      Data stop = st.top();
      st.pop();
      mult[stop.x] = stop.x;
      mult[stop.y] = stop.y;
      sz[stop.x] = stop.szx;
      sz[stop.y] = stop.szy;
      curr_verdict = stop.verdict;
    }
  }
}

int sol[1 + nmax];
int n, m, q;

void extract(int pos, int x, int y) {
  if(Dsu::curr_verdict == 1) {
    sol[pos] = y;
    return ;
  }
  x = std::max(x, pos + 1);

  for(int i = y - 1; x <= i; i--) {
    Dsu::unite(v[i][0], v[i][1]);
    if(Dsu::curr_verdict == 1) {
      sol[pos] = i;
      break;
    }
  }
  for(int i = y - 1; sol[pos] <= i; i--)
    Dsu::undo();
}

void divide(int from, int to, int x, int y) {
  if(to < from)
    return ;
  int mid = (from + to) / 2;
  for(int i = from + 1; i <= mid; i++)
    Dsu::unite(v[i][0], v[i][1]);
  extract(mid, x, y);  
  for(int i = from + 1; i <= mid; i++)
    Dsu::undo();

  for(int i = y - 1; sol[mid] <= i; i--)
    Dsu::unite(v[i][0], v[i][1]);
  divide(from, mid - 1, x, sol[mid]);
  for(int i = y - 1; sol[mid] <= i; i--)
    Dsu::undo();
  for(int i = from + 1; i <= mid + 1; i++)
    Dsu::unite(v[i][0], v[i][1]);
  divide(mid + 1, to, sol[mid], y);
  for(int i = from + 1;i <= mid + 1; i++)
    Dsu::undo();
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n >> m >> q;
  for(int i = 1;i <= m; i++) 
    std::cin >> v[i][0] >> v[i][1];    
  Dsu::initialize(n);
  for(int i = 1;i <= m; i++)
    Dsu::unite(v[i][0], v[i][1]);
  if(Dsu::curr_verdict == 0) {
    for(int i = 1;i <= q; i++)
      std::cout << "NO\n";
    return 0;
  }
  for(int i = 1;i <= m; i++)
    Dsu::undo();
  divide(0, m, 1, m + 1);

  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    if(sol[x - 1] <= y) 
      std::cout << "NO\n";
    else
      std::cout << "YES\n";
  }
  return 0;
}