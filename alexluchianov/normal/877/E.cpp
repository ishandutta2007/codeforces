#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 200000;

vector<int> g[1 + nmax];
int start[1 + nmax], stop[1 + nmax], ptr = 0;

void dfs(int node){
  start[node] = ++ptr;
  for(int h = 0; h < g[node].size(); h++)
    dfs(g[node][h]);
  stop[node] = ptr;
}

class SegmentTree{
private:
  vector<int> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    if(lazy[node] == 1)
      aint[node] = (to - from + 1) - aint[node];
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to){
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }

  void update(int node, int from, int to, int x, int y){
    if(from == x && to == y){
      lazy[node] ^= 1;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y){
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

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n;
  for(int i = 2; i <= n; i++){
    int parent;
    cin >> parent;
    g[parent].push_back(i);
  }
  dfs(1);

  SegmentTree aint(n);
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    if(val == 1)
      aint.update(1, 1, n, start[i], start[i]);
  }
  cin >> q;
  for(int i = 1;i <= q; i++){
    string op;
    int x;
    cin >> op >> x;
    if(op == "get")
      cout << aint.query(1, 1, n, start[x], stop[x]) << '\n';
    else
      aint.update(1, 1, n, start[x], stop[x]);
  }
  return 0;
}