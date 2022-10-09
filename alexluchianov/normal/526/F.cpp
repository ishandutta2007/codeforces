#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <stack>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[1 + nmax];
class SegmentTree{
private:
  vector<pair<int,int>> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].first += lazy[node];
    lazy[node] = 0;
  }

  pair<int,int> join(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
      return {a.first, a.second + b.second};
    else
      return min(a, b);
  }

  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = {0, 1};
  }

  void update(int node, int from, int to, int x, int y, int val){
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
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    }
  }

  pair<int,int> query(int node, int from, int to, int x, int y){
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
        return join(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    v[x] = y;
  }

  SegmentTree aint(n);
  aint.build(1, 1, n);

  stack<int> stackmin, stackmax;
  stackmin.push(0);
  stackmax.push(0);
  ll result = 0;
  for(int i = 1;i <= n; i++){
    if(1 < i)
      aint.update(1, 1, n, 1, i - 1, -1);
    while(1 < stackmin.size() && v[i] <= v[stackmin.top()]){
      int pos = stackmin.top();
      stackmin.pop();
      aint.update(1, 1, n, stackmin.top() + 1, pos, (v[pos] - v[i]));
    }
    stackmin.push(i);
    while(1 < stackmax.size() && v[stackmax.top()] <= v[i]){
      int pos = stackmax.top();
      stackmax.pop();
      aint.update(1, 1, n, stackmax.top() + 1, pos, v[i] - v[pos]);
    }
    stackmax.push(i);

    result += aint.query(1, 1, n, 1, i).second;
  }
  cout << result;
  return 0;
}