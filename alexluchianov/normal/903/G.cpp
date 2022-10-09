#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

class SegmentTree{
private:
  std::vector<ll> aint;
  std::vector<ll> lazy;
public:
  void cleannode(int node, int from, int to) {
    if(from < to) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] = aint[node] + lazy[node];
    lazy[node] = 0;
  }
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }

  void update(int node, int from, int to, int x, int y, ll val) {
    if(from == x && to == y) {
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x) , y, val);
      aint[node] = std::min(aint[node * 2], aint[node * 2 +1]);
    }
  }

  ll query(int node, int from, int to, int x, int y) {
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
        return std::min(query(node * 2, from, mid, x, mid),
               query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

int const nmax = 200000;
ll a[5 + nmax], b[5 + nmax];
ll tob[5 + nmax];
struct Edges{
  int x;
  int y;
  int cap;
  bool operator < (Edges const oth) {
    return x < oth.x;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m >> q;
  for(int i = 1;i < n; i++) 
    std::cin >> a[i] >> b[i];
  std::vector<Edges> aux; 
  
  for(int i = 1; i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    aux.push_back({x, y, cost});
  }
  std::sort(aux.begin(), aux.end());
  SegmentTree aint(n);

  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, i, b[i]);
  
  for(int i = 0; i < aux.size(); i++) {
    if(aux[i].y == n) 
      tob[aux[i].x] += aux[i].cap;
    else {
      int acc = std::min(1LL * aux[i].cap, aint.query(1, 1, n, aux[i].y, n - 1));
      tob[aux[i].x] += acc;
      aint.update(1, 1, n, aux[i].y, n - 1, -acc);
    }
  }

  aint = SegmentTree(n);
  for(int i = 1;i <= n; i++) {
    tob[i] += tob[i - 1];
  }

  for(int i = 1;i <= n; i++) {
    aint.update(1, 1, n, i, i, tob[i] + a[i]);
  }
  std::cout << aint.query(1, 1, n, 1, n) << '\n';

  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    aint.update(1, 1, n, x, x, -a[x] + y);
    a[x] = y;
    std::cout << aint.query(1, 1, n, 1, n) << '\n';
  }
  return 0;
}