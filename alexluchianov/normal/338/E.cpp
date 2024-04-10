#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 150000;

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
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += lazy[node];
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = min(aint[node * 2], aint[node * 2 + 1]);
    }
  }

  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from ,to);
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
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y) {
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
        return min(query(node * 2, from, mid, x, mid), query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};
int v[1 + nmax];

int binarysearch(int from, int to, int val){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(val <= v[mid])
      return binarysearch(mid, to, val);
    else
      return binarysearch(from, mid - 1, val);
  } else
    return from;
}

int v2[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  cin >> m >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  reverse(v + 1, v + n + 1);
  v[0] = k;
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++)
    aint.update(1, 0, n, i, n, 1);

  int result = 0;
  for(int i = 1;i <= m; i++) {
    cin >> v2[i];
    int pos = binarysearch(0, n, k - v2[i]);
    aint.update(1, 0, n, pos, n, -1);

    if(n < i){
      int pos2 = binarysearch(0, n, k - v2[i - n]);
      aint.update(1, 0, n, pos2, n, 1);
    }
    if(n <= i)
      result += (0 <= aint.query(1, 0, n, 0, n));
  }
  cout << result << '\n';
  return 0;
}