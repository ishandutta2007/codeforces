#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

class SegmentTree{
private:
  struct Node{
    short result;
    short sz;
    short suff;
    short pref;
    Node(int val = 0){
      sz = 1;
      result = suff = pref = val;
    }
    Node operator + (Node const &a) const{
      Node sol;
      sol.result = MAX(MAX(result, a.result), suff + a.pref);
      sol.sz = sz + a.sz;
      if(a.sz == a.suff)
        sol.suff = suff + a.sz;
      else
        sol.suff = a.suff;
      if(sz == pref)
        sol.pref = sz + a.pref;
      else
        sol.pref = pref;
      return sol;
    }
  };
public:
  vector<Node> aint;
  SegmentTree(int n = 0){
    aint.resize(1 + 4 * n);
  }
  void computenode(int node, int from, int to){
    aint[node] = aint[node * 2] + aint[node * 2 + 1];
  }

  void update(int node, int from, int to, int x, int val){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      computenode(node, from, to);
    } else
      aint[node] = val;
  }

  Node realquery(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return realquery(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return realquery(node * 2 + 1, mid + 1, to, x, y);
      else
        return realquery(node * 2, from, mid, x, mid) + realquery(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
  int query(int node, int from, int to, int x, int y){
    return realquery(node, from, to, x, y).result;
  }
};
int const nmax = 2000;
int up[1 + nmax][1 + nmax];
SegmentTree line[1 + nmax];
int n, m;

void activate(int x, int y, int val){
  line[x].update(1, 1, m, y, val);
}
vector<pair<short,short>> frec[1 + nmax];

int query(int sz){
  int result = 0;
  for(int i = 1;i <= n; i++)
    result |= (sz <= line[i].query(1, 1, m, 1, m));
  return result;
}

void lower(int level){
  for(int h = 0; h < frec[level].size(); h++){
    int x = frec[level][h].first;
    int y = frec[level][h].second;
    if(up[x][y] == level)
      activate(x, y, 1);
  }
  frec[level].clear();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k;
  cin >> n >> m >> k;
  for(int i = 1;i <= n; i++)
    line[i] = SegmentTree(m);

  int result = min(n, m);
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++){
      char val;
      cin >> val;
      if(val == '.')
        up[i][j] = up[i - 1][j] + 1;
      else
        up[i][j] = 0;
      if(result <= up[i][j])
        activate(i, j, 1);
      frec[up[i][j]].push_back({i, j});
    }

  while(1 <= result && query(result) == 0) {
    result--;
    lower(result);
  }

  for(int i = 1;i <= k; i++){
    int x, y;
    cin >> x >> y;
    for(int i = x; i <= n; i++) {
      up[i][y] = min(up[i][y], i - x);
      if(up[i][y] < result)
        frec[up[i][y]].push_back({i, y});
      if(result <= up[i][y])
        activate(i, y, 1);
      else
        activate(i, y, 0);
    }

    while(1 <= result && query(result) == 0) {
      result--;
      lower(result);
    }
    cout << result << '\n';
  }
  return 0;
}