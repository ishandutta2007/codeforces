#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 77777;
int const modulo = 777777777;
class Matrix {
  public:  
    int n, m;
    int mat[3][3];
    Matrix(int n_ = 0, int m_ = 0) {
      n = n_;
      m = m_;
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          mat[i][j] = 0;
    }
    Matrix operator * (Matrix a) {
      Matrix result(n, a.m);
      assert(m == a.n);
      for(int i = 0; i < n; i++)
        for(int j = 0; j < a.m; j++)
          result.mat[i][j] = (result.mat[i][j] + 1LL * mat[i][0] * a.mat[0][j] + 
                                                 1LL * mat[i][1] * a.mat[1][j] + 
                                                 1LL * mat[i][2] * a.mat[2][j]
                            
          ) % modulo;
      return result;
    }
};

Matrix extract(int val) {
  Matrix result(3, 3);
  if(val == 0) 
    result.mat[0][0] = result.mat[1][1] = result.mat[2][2] = 1;
  else
    result.mat[val - 1][val - 1] = 1;
  return result;
}

class SegmentTree{
  public:
    std::vector<Matrix> aint;
    SegmentTree(int n) {
      aint.resize(1 + 4 * n);
    }
    void computenode(int node, int from, int to) {
      aint[node] = aint[node * 2] * aint[node * 2 + 1];
    }
    void build(int node, int from, int to, Matrix base) {
      if(from < to) {
        int mid = (from + to) / 2;
        build(node * 2, from, mid, base);
        build(node * 2 + 1, mid + 1, to, base);
        computenode(node, from, to);
      } else  {
        if(from % 2 == 0)
          aint[node] = base;
        else
          aint[node] = extract(0);
      }
    }
    void update(int node, int from, int to, int x, Matrix val) {
      if(from < to) {
        int mid = (from + to) / 2;
        if(x <= mid)
          update(node * 2, from, mid, x, val);
        else
          update(node * 2 + 1, mid + 1, to, x, val);
        computenode(node, from, to);
      } else {
        aint[node] = val;
      }
    }
    Matrix _query(int node, int from, int to, int x, int y) {
      if(from == x && to == y)
        return aint[node];
      else {
        int mid = (from + to) / 2;
        if(x <= mid && y <= mid)
          return _query(node * 2, from, mid, x, y);
        else if(mid + 1 <= x && mid + 1 <= y)
          return _query(node * 2 + 1, mid + 1, to, x, y);
        else
          return _query(node * 2, from, mid, x, mid) * _query(node * 2 + 1, mid + 1, to, mid + 1, y);
      }
    }
    int query() {
      int result = 0;
      for(int i = 0;i < 3; i++) {
        for(int j = 0;j < 3; j++) {
          result += aint[1].mat[i][j];
          if(modulo <= result)
            result -= modulo;
        }
      }
      return result;
    }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int n, q;
  std::cin >> n >> q;
  Matrix base(3, 3);
  for(int i = 0;i < 3; i++)
    for(int j = 0; j < 3; j++)
      std::cin >> base.mat[i][j];
  int lim = 2 * n - 1;
  SegmentTree aint(lim);
  aint.build(1, 1, lim, base);
  for(int i = 1;i <= q; i++) {
    int pos, x;
    std::cin >> pos >> x;
    aint.update(1, 1, lim, pos * 2 - 1, extract(x));
    std::cout << aint.query() << '\n';
  }
}