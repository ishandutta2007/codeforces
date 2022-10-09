#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 500000;
ll const inf = 1000000000000000000;

ll orig[3][5 + nmax];
ll start[5 + nmax], stop[5 + nmax];

struct Query {
  int x;
  int y;
  int cost;
  bool operator < (Query const oth) {
    return y < oth.y;
  }
};

class SegmentTree{
private:
  std::vector<ll> aint;
  std::vector<ll> lazy;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n, -inf);
  }
  void build(int node, int from, int to, ll *arr) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, arr);
      build(node * 2 + 1, mid + 1, to, arr);
      aint[node] = std::max(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = arr[from];
  }
  
  void clean_node(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      lazy[node * 2] = std::max(lazy[node * 2], lazy[node]);
      lazy[node * 2 + 1] = std::max(lazy[node * 2 + 1], lazy[node]);
    }
    aint[node] = std::max(aint[node], lazy[node]);
    lazy[node] = -inf;
  }

  void update(int node, int from, int to, int x, int y, ll val) {
    if(from == x && to == y) {
      lazy[node] = val;
      clean_node(node, from, to);
    } else {
      int mid = (from + to) / 2;
      clean_node(node * 2, from, mid);
      clean_node(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, val);
      aint[node]= std::max(aint[node * 2], aint[node * 2 + 1]);
    }
  }
  ll query(int node, int from, int to, int x, int y) {
    clean_node(node, from, to);
    if(x == from && to == y) {
      return aint[node];
    } else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return std::max(query(node * 2, from, mid, x, mid),
                        query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }

  void extract(int node, int from, int to, ll *arr) {
    clean_node(node, from, to);
    if(from < to) {
      int mid = (from + to) / 2;
      extract(node * 2, from, mid, arr);
      extract(node * 2 + 1, mid + 1, to, arr);
    } else
      arr[from] = aint[node];
  }
};

class SegmentTreePair {
private:
  struct Node{
    ll result;
    ll x;
    ll y;
    Node operator + (Node const oth) {
      return {std::max(std::max(result, oth.result), x + oth.y),
              std::max(x, oth.x),
              std::max(y, oth.y)};
    }
  };
  std::vector<Node> aint;
public:
  SegmentTreePair(int n) {
    aint.resize(1 + 4 * n);
  }
  void build(int node, int from, int to, ll *arr, ll *arr2) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, arr, arr2);
      build(node * 2 + 1, mid + 1, to, arr, arr2);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = {arr[from] + arr2[from], arr[from], arr2[from]};
  }
  Node _query(int node, int from, int to, int x, int y) {
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return _query(node * 2, from, mid, x, mid) +
               _query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
  ll query(int node, int from, int to, int x, int y) {
    return _query(node, from, to, x, y).result;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int h = 0; h < 3; h++)
    for(int i = 1;i <= n; i++) {
      std::cin >> orig[h][i];
      orig[h][i] += orig[h][i - 1];
    }
  
  for(int i = 1; i <= n; i++) {
    start[i] = orig[0][i] - orig[1][i - 1];
    stop[i] = orig[2][n] - orig[2][i - 1] + orig[1][i];
  }
  std::vector<Query> queries;
  for(int i = 1;i <= q; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    queries.push_back({x, y, cost});
  }

  SegmentTree base(n);
  base.build(1, 1, n, start);
  std::sort(queries.begin(), queries.end());
  for(const auto &ev : queries) {
    ll result = base.query(1, 1, n, ev.x, ev.y);
    if(ev.y < n)
      base.update(1, 1, n, ev.y + 1, ev.y + 1, result - ev.cost);
  }
  base.extract(1, 1, n, start);

  SegmentTreePair dp(n);
  dp.build(1, 1, n, start, stop);
  ll answer = -inf;
  for(const auto &ev : queries) {
    answer = std::max(answer, dp.query(1, 1, n, ev.x, ev.y) - ev.cost);
  }
  std::cout << answer << '\n';
  return 0;
}