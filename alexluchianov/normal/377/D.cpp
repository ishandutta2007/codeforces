#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
struct Person{
  int l;
  int val;
  int r;
} v[1 + nmax];

struct Node{
  int val;
  int pos;
  Node operator + (Node const &a) const {
    if(val < a.val)
      return a;
    else
      return *this;
  }
};

class SegmentTree{
private:
  vector<Node> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
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
      aint[node] = {0, from};
  }
  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node].val += lazy[node];
    lazy[node] = 0;
  }

  void update(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);
    if(from == x && to == y) {
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(mid, y), val);
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
vector<pair<int,int>> updates[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i].l >> v[i].val >> v[i].r;
    updates[v[i].val].push_back({i, 1});
    updates[v[i].l - 1].push_back({i, -1});
  }
  SegmentTree aint(nmax);
  aint.build(1, 1, nmax);

  int result = 0, bestl = 0, bestr = 0;
  for(int i = nmax; 1 <= i; i--){
    for(int h = 0; h < updates[i].size(); h++){
      int pos = updates[i][h].first;
      int val = updates[i][h].second;
      aint.update(1, 1, nmax, v[pos].val, v[pos].r, val);
    }
    Node result2 = aint.query(1, 1, nmax, i, nmax);
    if(result < result2.val){
      result = result2.val;
      bestl = i;
      bestr = result2.pos;
    }
  }

  cout << result << '\n';
  for(int i = 1;i <= n; i++)
    if(bestl <= v[i].val && v[i].val <= bestr && v[i].l <= bestl && bestr <= v[i].r)
      cout << i << " ";
  return 0;
}