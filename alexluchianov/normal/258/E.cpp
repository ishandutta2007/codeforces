#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];
int st[1 + nmax], dr[1 + nmax], ptr = 0;

void dfs(int node, int parent){
  st[node] = ++ptr;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
  dr[node] = ptr;
}
vector<int> op[1 + nmax];
int sol[1 + nmax];

struct Node{
  int smin;
  int scount;
  Node operator + (Node const &a) const{
    if(smin < a.smin)
      return *this;
    else if(a.smin < smin)
      return a;
    else
      return {smin, scount + a.scount};
  }
};

class SegmentTree{
private:
  int n;
  vector<Node> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
    this->n = n;
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }

  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {0, 1};
  }

  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].smin += lazy[node];
    lazy[node] = 0;
  }

  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);

    if(from == x && to == y){
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }
  Node query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};

void solve(int node, int parent, int &n, SegmentTree &aint){
  if(0 < op[node].size())
    aint.update(1, 1, n, st[node], dr[node], 1);

  for(int h = 0; h < op[node].size(); h++){
    int to = op[node][h];
    aint.update(1, 1, n, st[to], dr[to], 1);
  }

  Node result = aint.query(1, 1, n, 1, n);
  if(result.smin == 0)
    sol[node] = (n - 1) - result.scount;
  else
    sol[node] = (n - 1);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      solve(to, node, n, aint);
  }

  if(0 < op[node].size())
    aint.update(1, 1, n, st[node], dr[node], -1);

  for(int h = 0; h < op[node].size(); h++){
    int to = op[node][h];
    aint.update(1, 1, n, st[to], dr[to], -1);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    op[x].push_back(y);
    op[y].push_back(x);
  }
  SegmentTree aint(n);
  aint.build(1, 1, n);
  solve(1, 0, n, aint);

  for(int i = 1;i <= n; i++)
    if(sol[i] < 0)
      cout << 0 << " ";
    else
      cout << sol[i] << " ";
  return 0;
}