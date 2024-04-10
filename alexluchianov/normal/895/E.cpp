#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

class SegmentTree{
private:
  vector<ld> aint;
  vector<ld> lazy1;
  vector<ld> lazy2;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    lazy1.resize(1 + 4 * n);
    lazy2.resize(1 + 4 * n);
    for(int i = 1; i <= 4 * n; i++)
      lazy1[i] = 1;
  }

  void cleannode(int node, int from, int to){
    if(lazy1[node] == 1 && lazy2[node] == 0)
      return ;

    if(from < to){
      int mid = (from + to) / 2;
      lazy1[node * 2] *= lazy1[node];
      lazy2[node * 2] *= lazy1[node];
      lazy2[node * 2] += lazy2[node];

      lazy1[node * 2 + 1] *= lazy1[node];
      lazy2[node * 2 + 1] *= lazy1[node];
      lazy2[node * 2 + 1] += lazy2[node];
    }
    aint[node] = aint[node] * lazy1[node] + (to - from + 1) * lazy2[node];
    lazy1[node] = 1;
    lazy2[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
  }

  void update1(int node, int from, int to, int x, int y, ld val){
    if(from == x && to == y){
      lazy1[node] *= val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update1(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update1(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  void update2(int node, int from, int to, int x, int y, ld val){
    if(from == x && to == y){
      lazy2[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update2(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update2(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  ld query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1,mid + 1, to, x, y);
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
  cin >> n >> q;
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++){
    ld val;
    cin >> val;
    aint.update2(1, 1, n, i, i, val);
  }

  for(int i = 1;i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x, y, x2, y2;
      cin >> x >> y >> x2 >> y2;
      ld sum1 = aint.query(1, 1, n, x, y);
      ld sum2 = aint.query(1, 1, n, x2, y2);
      aint.update1(1, 1, n, x, y, (double)(y - x) / (y - x + 1));
      aint.update1(1, 1, n, x2, y2, (double)(y2 - x2) / (y2 - x2 + 1));
      aint.update2(1, 1, n, x, y, sum2 / (y - x + 1) / (y2 - x2 + 1));
      aint.update2(1, 1, n, x2, y2, sum1 / (y2 - x2 + 1) / (y - x + 1));

    } else{
      int x, y;
      cin >> x >> y;
      cout << setprecision(6) << fixed << aint.query(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}