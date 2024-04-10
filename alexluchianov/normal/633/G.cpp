#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <bitset>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 2000;
std::vector<std::vector<int>> g;
int start[1 + nmax], stop[1 + nmax], ptr = 0;

void dfs(int node, int parent) {
  start[node] = ++ptr;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
  stop[node] = ptr;
}

bool isprime(int number) {
  if(number < 2)
    return 0;
  for(int i = 2;i * i <= number; i++)
    if(number % i == 0)
      return 0;
  return 1;
}

int m;
std::bitset<sigma> base;

std::bitset<sigma> shift(std::bitset<sigma> start, int k) {
  k %= m;
  std::bitset<sigma> result = (start << k);
  result = ((result & base) | (result>>m));
  return result & base;
}

class SegmentTree{
private:
  std::vector<std::bitset<sigma>> aint;
  std::vector<int> lazy;
  void cleannode(int node, int from, int to) {
    if(lazy[node] == 0)
      return ;
    if(from < to) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] = shift(aint[node], lazy[node]);
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      aint[node] = (aint[node * 2] | aint[node * 2 + 1]);
    }
  }
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void build(int node, int from, int to, std::vector<int> &aux) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, aux);
      build(node * 2 + 1, mid + 1, to, aux);
      computenode(node, from, to);
    } else
      aint[node][aux[from]] = 1;
  }
  void update(int node, int from, int to, int x, int y, int val) {
    if(from == x && to == y) {
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
  
  std::bitset<sigma> query(int node, int from, int to, int x, int y) {
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
        return (query(node * 2, from, mid, x, mid) | 
               query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
};

void print(std::bitset<sigma> aux) {
  for(int i = 0; i < m; i++)
    std::cout << aux[i];
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::bitset<2> mybitset;

  int n;
  std::cin >> n >> m;
  std::bitset<sigma> primemap;
  for(int i = 0; i < m; i++)
    base[i] = 1;
  for(int i = 0; i < m; i++)
    primemap[i] = isprime(i);

  std::vector<int> v(1 + n);
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  g.resize(1 + n);
  for(int i = 1;i < n; i++){
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  std::vector<int> init(1 + n);
  for(int i = 1;i <= n; i++)
    init[start[i]] = v[i] % m;
  SegmentTree aint(n);

  aint.build(1, 1, n, init);
  int q;
  std::cin >> q;

  for(int i = 1;i <= q; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int x, val;
      std::cin >> x >> val;
      val %= m;
      aint.update(1, 1, n, start[x], stop[x], val);
    } else {
      int x;
      std::cin >> x;
      std::cout << (aint.query(1, 1, n, start[x], stop[x]) & primemap).count() << '\n';
    }
  }
  return 0;
}