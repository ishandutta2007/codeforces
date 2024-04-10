#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const lgmax = 20;
int const nmax = 100000;

struct Point{
  ll x;
  ll y;
} v[1 + nmax];

ll det3(Point a, Point b, Point c){
  ll splus = a.x * b.y + a.y * c.x + b.x * c.y;
  ll sminus = a.x * c.y + a.y * b.x + b.y * c.x;
  return splus - sminus;
}

int far[1 + lgmax][1 + nmax];
int level[1 + nmax];

int getlca(int x, int y){
  if(level[x] < level[y])
    swap(x, y);
  for(int h = lgmax; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax; 0 <= h; h--)
    if(far[h][x] != far[h][y]){
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i].x >> v[i].y;
  stack<int> st;
  for(int i = n; 1 <= i; i--){
    while(1 < st.size()){
      int inter = st.top();
      st.pop();
      if(0 <= det3(v[i], v[st.top()], v[inter])){
        st.push(inter);
        break;
      }
    }
    if(0 < st.size())
      far[0][i] = st.top();
    else
      far[0][i] = n + 1;
    st.push(i);
    level[i] = level[far[0][i]] + 1;
  }


  for(int h = 1; h <= lgmax; h++)
    for(int i = 1; i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    int lca = getlca(x, y);
    cout << lca << " ";
  }
  return 0;
}