#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;
int const nmax = 100000;

struct Node{
  int result;
  int maxel;
  int minel;
  int suf;
  int pref;
  Node operator + (Node const a) const {
    Node product;
    product.result = max(max(result, a.result), max(suf + a.maxel, maxel + a.pref));
    product.maxel = max(maxel, a.maxel);
    product.minel = min(minel, a.minel);
    product.suf = max(max(suf, a.suf), maxel + a.minel * -2);
    product.pref = max(max(a.pref, pref), minel * -2 + a.maxel);
    return product;
  }
};

class SegmentTree{
private:
  vector<Node> aint;
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
    aint[node].maxel += lazy[node];
    aint[node].minel += lazy[node];
    aint[node].suf -= lazy[node];
    aint[node].pref -= lazy[node];
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to){
    if(from < to){
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
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
        update(node * 2 + 1, mid + 1 , to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
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
char v[1 + 2 * nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;
  int n2 = 2 * n - 1;
  for(int i = 1; i < n2; i++)
    cin >> v[i];
  int sum = 0;
  SegmentTree aint(n2);
  for(int i = 1;i < n2; i++){
    if(v[i] == '(')
      sum++;
    else
      sum--;
    aint.update(1, 1, n2, 1 + i, 1 + i, sum);
  }

  cout << aint.query(1, 1, n2, 1, n2).result << '\n';
  for(int i = 1;i <= q; i++){
    int x, y;
    cin >> x >> y;
    if(y < x)
      swap(x, y);
    if(v[x] != v[y]){
      if(v[x] == '(')
        aint.update(1, 1, n2, 1 + x, y, -2);
      else
        aint.update(1, 1, n2, 1 + x, y, 2);
      swap(v[x], v[y]);
    }
    cout << aint.query(1, 1, n2, 1, n2).result << '\n';
  }
  return 0;
}