#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const inf = 1000000000;

struct Edge{
  int x;
  int y;
  int height;
  bool operator < (Edge const &a) const{
    return height < a.height;
  }
} v[1 + nmax];

struct Element{
  int x;
  int y;
  int id;
  bool operator < (Element const &a) const{
    if(x != a.x)
      return x < a.x;
    else
      return id > a.id;
  }
};

int intersect(int x, int y, int x2, int y2){
  return MAX(0, MIN(y, y2) - MAX(x, x2));
}
int dp[1 + nmax];

int main()
{
  int n, top;
  cin >> n >> top;
  vector<Edge> edges;
  for(int i = 1;i <= n; i++){
    Edge e;
    cin >> e.height >> e.x >> e.y;
    v[i] = e;
  }
  v[0] = {-inf, inf, 0};

  v[n + 1] = {-inf, inf, top};
  sort(v + 1, v + n + 1);
  set<Element> myset;
  myset.insert({-inf, inf, n + 1});
  myset.insert({-inf - 1, -inf, n + 2});
  myset.insert({inf, inf + 1, n + 3});
  dp[n + 1] = 2 * inf;

  for(int i = n; 0 <= i; i--){
    set<Element>::iterator it;
    it = myset.upper_bound({v[i].x, v[i].y, i});
    it--;
    vector<Element> cand;
    while(0 < intersect(it->x, it->y, v[i].x, v[i].y)){
      cand.push_back(*it);
      myset.erase(it++);
    }
    myset.insert({v[i].x, v[i].y, i});
    for(int h = 0; h < cand.size(); h++){
      int from = cand[h].id;
      if(intersect(v[i].x, v[i].y, v[from].x, v[from].y) == intersect(v[i].x, v[i].y, cand[h].x, cand[h].y))
        dp[i] = MAX(dp[i], MIN(dp[from], intersect(v[i].x, v[i].y, v[from].x, v[from].y)));
      if(cand[h].x < v[i].x)
        myset.insert({cand[h].x, v[i].x, cand[h].id});
      if(v[i].y < cand[h].y)
        myset.insert({v[i].y, cand[h].y, cand[h].id});
    }
  }
  cout << dp[0];
  return 0;
}