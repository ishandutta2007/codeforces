#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
int const lgmax = 30;

struct Node{
  int ptr;
  int v[1 + lgmax];
  int bit[1 + lgmax];
};

class SegmentTree{
  private:
    std::vector<Node> aint;
  public:
    SegmentTree(int n) {
      aint.resize(1 + 4 * n);
    }

    void join(int from, int to) {
      for(int i = 0; i < aint[from].ptr; i++) {
        int val = aint[from].v[i];
        for(int j = 0; j < aint[to].ptr; j++)
          if((1 << aint[to].bit[j]) & val)
            val ^= aint[to].v[j];
        if(0 < val) {
          aint[to].v[aint[to].ptr] = val; 
          aint[to].bit[aint[to].ptr] = __builtin_ctz(val);
          aint[to].ptr++;
        }
      }
    }

    void makeCopy(int from, int to) {
      aint[to].ptr = aint[from].ptr;
      for(int i = 0; i < aint[to].ptr; i++) {
        aint[to].v[i] = aint[from].v[i];
        aint[to].bit[i] = aint[from].bit[i];
      }
    }

    void build(int node, int from, int to, std::vector<int> &aux) {
      if(from < to) {
        int mid = (from + to) / 2;
        build(node * 2, from, mid, aux);
        build(node * 2 + 1, mid + 1, to, aux);

        makeCopy(node * 2, node);
        join(node * 2 + 1, node);
      } else {
        int val = aux[from] ^ aux[from + 1];
        if(val == 0)
          aint[node].ptr = 0;
        else {
          aint[node].ptr = 1;
          aint[node].v[0] = val;
          aint[node].bit[0] = __builtin_ctz(val);
        }
      }
    }
    void update(int node, int from, int to, int x, int val) {
      if(from < to) {
        int mid = (from + to) / 2;
        if(x <= mid)
          update(node * 2, from, mid, x, val);
        else
          update(node * 2 + 1, mid + 1, to, x, val);

        makeCopy(node * 2, node);
        join(node * 2 + 1, node);
      } else {
        if(val == 0)
          aint[node].ptr = 0;
        else {
          aint[node].ptr = 1;
          aint[node].v[0] = val;
          aint[node].bit[0] = __builtin_ctz(val);
        }
      }
    }
    void query(int node, int from, int to, int x, int y) {
      if(from == x && to == y) 
        join(node, 0);
      else {
        int mid = (from + to) / 2;
        if(x <= mid)
          query(node * 2, from, mid, x, std::min(y, mid));
        if(mid + 1 <= y)
          query(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y);
      }
    }
    void setStart(int number) {
      if(number == 0)
        aint[0].ptr = 0;
      else {
        aint[0].ptr = 1;
        aint[0].v[0] = number;
        aint[0].bit[0] = __builtin_ctz(number);
      }
    }
    int getAnswer() {
      return aint[0].ptr;
    }
};

class FenwickTree{
  private:
    std::vector<int> aib;
    int n;
  public:
    FenwickTree(int n_) {
      n = n_;
      aib.resize(1 + n);
    }
    void update(int pos, int val) {
      for(int x = pos; x <= n; x += ((x & (x - 1)) ^ x))
        aib[x] ^= val;
    }
    int query(int pos) {
      int result = 0;
      for(int x = pos; 0 < x; x = (x & (x - 1)))
        result ^= aib[x];
      return result;
    }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  if(n == 1) {
    int val;
    std::cin >> val;
    for(int i = 1;i <= q; i++) {
      int op;
      std::cin >> op;
      if(op == 1) {
        int x, y, cost;
        std::cin >> x >> y >> cost;
        val ^= cost;
      } else {
        int x, y;
        std::cin >> x >> y;
        if(val == 0)
          std::cout << 1 << '\n';
        else
          std::cout << 2 << '\n';
      }
    }
    return 0;
  }

  std::vector<int> aux(n + 1);
  for(int i = 1;i <= n; i++)
    std::cin >> aux[i];
  SegmentTree aint(n + 1);
  aint.build(1, 1, n - 1, aux);

  FenwickTree aib(n);
  for(int i = 1;i <= n; i++) {
    aib.update(i, aux[i]);
    aib.update(i + 1, aux[i]);
  }

  for(int i = 1;i <= q; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int x, y, cost;
      std::cin >> x >> y >> cost;
      if(1 < x)
        aint.update(1, 1, n - 1, x - 1, cost ^ aib.query(x - 1) ^ aib.query(x));
      if(y < n)
        aint.update(1, 1, n - 1, y, cost ^ aib.query(y) ^ aib.query(y + 1) );
      aib.update(x, cost);
      aib.update(y + 1, cost);
    } else {
      int x, y;
      std::cin >> x >> y;
      if(x == y) {
        if(aib.query(x) == 0)
          std::cout << 1 << '\n';
        else
          std::cout << 2 << '\n';
      } else {
        int number = aib.query(x);
        aint.setStart(number);
        aint.query(1, 1, n - 1, x, y - 1);
        std::cout << (1 << aint.getAnswer()) << '\n';
      }
    }
  }
  return 0;
}