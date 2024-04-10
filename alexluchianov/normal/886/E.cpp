#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;

class SegmentTree{
private:
  vector<int> aint;
  vector<int> lazy;
public:
  SegmentTree(int n){
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }
  void build(int node, int from, int to){
    lazy[node] = 1;
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
    }
  }
  void cleannode(int node, int from, int to){
    if(1 < lazy[node]) {
      if(from < to){
        int mid = (from + to) / 2;
        lazy[node * 2] = 1LL * lazy[node * 2] * lazy[node] % modulo;
        lazy[node * 2 + 1] = 1LL * lazy[node * 2 + 1] * lazy[node] % modulo;
      }
      aint[node] = 1LL * aint[node] * lazy[node] % modulo;
      lazy[node] = 1;
    }
  }

  void computenode(int node, int from, int to){
    if(from < to) {
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
      if(modulo <= aint[node])
        aint[node] -= modulo;
    }
  }

  void update(int node, int from, int to, int x, int val){
    cleannode(node, from, to);
    if(from < to){
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      computenode(node, from, to);
    } else {
      aint[node] += val;
      if(modulo <= aint[node])
        aint[node] -= modulo;
    }
  }

  void updateinterval(int node, int from, int to, int x, int y, int val){
    cleannode(node, from, to);

    if(from == x && to == y){
      lazy[node] = 1LL * lazy[node] * val % modulo;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        updateinterval(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        updateinterval(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);

    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      int result = 0;
      if(x <= mid)
        result += query(node * 2, from, mid, x, MIN(mid, y));

      if(mid + 1 <= y) {
        result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
        if(modulo <= result)
          result -= modulo;
      }
      return result;
    }
  }
};

int main()
{
  int n, k;
  cin >> n >> k;
  SegmentTree dp(n);
  dp.build(1, 1, n);

  dp.update(1, 1, n, 1, 1);
  for(int i = 2;i <= n; i++){
    int result = dp.query(1, 1, n, MAX(1, i - k), i - 1);
    dp.update(1, 1, n, i, result);
    dp.updateinterval(1, 1, n, 1, i - 1, i - 1);
  }
  int result = 1;
  for(int i = 1;i <= n; i++)
    result = 1LL * result * i % modulo;
  cout << (result - dp.query(1, 1, n, 1, n) + modulo) % modulo;
  return 0;
}