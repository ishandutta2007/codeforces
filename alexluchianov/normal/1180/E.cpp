#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 1000000;

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

  int query(int node, int from, int to, int x, int y){
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
        return min(query(node * 2, from, mid, x, mid), query(node * 2 + 1,mid + 1, to, mid + 1, y));
    }
  }

  int binarysearch(int node, int from, int to, int target){
    cleannode(node, from, to);
    if(from < to) {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(aint[node * 2 + 1] <= target)
        return binarysearch(node * 2 + 1, mid + 1, to, target);
      else
        return binarysearch(node * 2, from, mid, target);
    } else
      return from;
  }
};
int v1[1 + nmax];
int v2[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  SegmentTree aint(nmax);
  for(int i = 1;i <= n; i++) {
    cin >> v1[i];
    aint.update(1, 0, nmax, 0, v1[i], -1);
  }
  for(int i = 1;i <= m; i++){
    cin >> v2[i];
    aint.update(1, 0, nmax, 0, v2[i], 1);
  }
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++){
    int op, pos, val;
    cin >> op >> pos >> val;
    if(op == 1){
      aint.update(1, 0, nmax, 0, v1[pos], 1);
      v1[pos] = val;
      aint.update(1, 0, nmax, 0, v1[pos], -1);
    } else {
      aint.update(1, 0, nmax, 0, v2[pos], -1);
      v2[pos] = val;
      aint.update(1, 0, nmax, 0, v2[pos], 1);
    }
    int result = aint.binarysearch(1, 0, nmax, -1);
    if(result == 0)
      cout << -1 << '\n';
    else
      cout << result << '\n';
  }
  return 0;
}