#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
int const modulo = 998244353;

struct Matrix {
  int v[2][2];
  Matrix() {
    v[0][0] = v[0][1] = v[1][0] = v[1][1] = 0;
  }
  Matrix operator * (Matrix a) {
    Matrix result;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int h = 0; h < 2; h++) {
          result.v[i][j] += 1LL * v[i][h] * a.v[h][j] % modulo;
          if(modulo <= result.v[i][j])
            result.v[i][j] -= modulo;
        }
    return result;
  }
};

int extract(int val, int cif) {
  if(cif == 1 && val < 10) {
    int result = 0;
    for(int i = 0; i < 10; i++)
      if(0 <= val - i && val - i < 10)
        result++;
    return result;
  } else if(cif == 2 && 10 <= val) {
    int result = 0;
    for(int i = 0; i < 10; i++)
      if(0 <= val - i && val - i < 10)
        result++;
    return result;
  }
  return 0;
}

class SegmentTree{
private:
  std::vector<Matrix> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, Matrix val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = aint[node * 2] * aint[node * 2 + 1];
    } else
      aint[node] = val;
  }
  int query() {
    Matrix basic;
    basic.v[0][1] = 1;
    return (basic * aint[1]).v[0][1];
  }
};

int v[1 + nmax];

Matrix extract(int pos) {
  Matrix result;
  result.v[1][0] = 1;
  result.v[0][1] = extract(v[pos - 1] * 10 + v[pos], 2);
  result.v[1][1] = extract( v[pos], 1);
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1;i <= n; i++) {
    char ch;
    std::cin >> ch;
    v[i] = ch - '0';
  }
  SegmentTree aint(n);
  for(int i = 1;i <= n; i++)
    aint.update(1, 1, n, i, extract(i));

  for(int i = 1; i <= q; i++) {
    int pos, val;
    std::cin >> pos >> val;
    v[pos] = val;
    aint.update(1, 1, n, pos, extract(pos));
    if(pos < n)
      aint.update(1, 1, n, pos + 1, extract(pos + 1));
    std::cout << aint.query() << '\n';
  }
  return 0;
}