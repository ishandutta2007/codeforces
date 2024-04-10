#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;

class SegmentTree{
private:
  std::vector<ll> aint;
  std::vector<int> lazy;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }

  void computenode(int node, int from, int to) {
    if(from < to)
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
  }

  void cleannode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += 1LL * (to - from + 1) * lazy[node];
    lazy[node] = 0;
  }
  
  void update(int node, int from, int to, int x, int y, int val) {
    if(x == from && to == y) {
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
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};
int v[5 + nmax];
int nxt_left[5 + nmax], nxt_right[5 + nmax];
int queries[5 + nmax][2];
std::vector<int> event[5 + nmax];
ll sol[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n, q;
  std::cin >> n >> q;
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  v[0] = v[n + 1] = n + 1;
  for(int i = 1;i <= n; i++) {
    nxt_left[i] = i - 1;
    while(v[nxt_left[i]] < v[i])
      nxt_left[i] = nxt_left[nxt_left[i]];
  }
  for(int i = n; 1 <= i; i--) {
    nxt_right[i] = i + 1;
    while(v[nxt_right[i]] < v[i])
      nxt_right[i] = nxt_right[nxt_right[i]];
  }
  for(int i = 1; i <= q; i++) {
    std::cin >> queries[i][0];
    event[queries[i][0] - 1].push_back(i);
  }
  for(int i = 1; i <= q; i++) {
    std::cin >> queries[i][1];
    event[queries[i][1]].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    aint.update(1, 1, n, nxt_left[i] + 1, nxt_right[i] - 1, 1);
    for(int h = 0; h < event[i].size(); h++) {
      int id = event[i][h];
      int coef = 1;
      if(i != queries[id][1])
        coef = -1;
      sol[id] += coef * aint.query(1, 1, n, queries[id][0], queries[id][1]);

    }
  }
  for(int i = 1; i <= q; i++)
    std::cout << sol[i] << " ";
  return 0;
}