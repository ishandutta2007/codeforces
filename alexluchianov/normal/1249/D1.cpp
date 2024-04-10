#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

class SegmentTree{
/*
Update on interval +1
Query on interval for maximum
*/
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
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += lazy[node];
    lazy[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to)
      aint[node] = max(aint[node * 2], aint[node * 2 + 1]);
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
        update(node * 2, from, mid, x, min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, max(mid + 1, x), y, val);
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
        result = query(node * 2, from, mid, x, min(y, mid));
      if(mid + 1 <= y)
        result2 = query(node * 2 + 1, mid + 1, to, max(mid + 1, x), y);
      return max(result, result2);
    }
  }
};

int const nmax = 200000;

struct Segment{
  int x;
  int y;
  int id;
  bool operator < (Segment const &a) const{
    return y < a.y;
  }
} v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;

  SegmentTree aint(nmax);
  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    v[i] = {x, y, i};
  }
  sort(v + 1, v + n + 1);

  vector<int> sol;
  for(int i = 1;i <= n ; i++){
    if(aint.query(1, 1, nmax, v[i].x, v[i].y) < k)
      aint.update(1, 1, nmax, v[i].x, v[i].y, 1);
    else
      sol.push_back(v[i].id);
  }

  cout << sol.size() << '\n';
  sort(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  cout << '\n';
  return 0;
}