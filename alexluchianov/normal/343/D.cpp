#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
vector<int> g[1 + nmax];
int st[1 + nmax], dr[1 + nmax], ptr = 0;

void dfs(int node, int parent){
  st[node] = ++ptr;
  for(int h = 0;h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
  dr[node] = ptr;
}

class SegmentTree{
private:
  int n;
  vector<int> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
    this->n = n;
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }

  void cleannode(int node, int from, int to){
    if(from < to){
      lazy[node * 2] = MAX(lazy[node * 2], lazy[node]);
      lazy[node * 2 + 1] = MAX(lazy[node * 2 + 1], lazy[node]);
    }
    aint[node] = MAX(aint[node], lazy[node]);
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = MAX(aint[node * 2], aint[node * 2 + 1]);
  }

  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);
    if(from == x && to == y){
      lazy[node] = MAX(lazy[node], val);
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x , MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }
  int query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      int result = 0, result2 = 0;
      if(x <= mid)
        result = query(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        result2 = query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      return MAX(result, result2);
    }
  }
};

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  int n, m;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  SegmentTree water(n), cleared(n);
  cin >> m;
  for(int i = 1;i <= m; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x;
      cin >> x;
      water.update(1, 1, n, st[x], dr[x], i);
    } else if(op == 2){
      int x;
      cin >> x;
      cleared.update(1, 1, n, st[x], st[x], i);
    } else if(op == 3){
      int x;
      cin >> x;
      if(cleared.query(1, 1, n, st[x], dr[x]) < water.query(1, 1, n, st[x], st[x]))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
  }
  return 0;
}