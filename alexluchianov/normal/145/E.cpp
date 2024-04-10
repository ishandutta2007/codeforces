#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;

class SegmentTree{
private:
  class Node{
    public:
    int dp[2][2];
    Node() {
      dp[0][0] = dp[0][1] = 0;
      dp[1][0] = dp[1][1] = 0;
    }
    Node operator + (Node a) {
      Node result;
      for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
          result.dp[i][j] = std::max(dp[i][i] + a.dp[j][j], std::max(dp[i][i] + a.dp[i][j], dp[i][j] + a.dp[j][j]));
      return result;
    }
  };
public:
  std::vector<Node> aint;
  std::vector<int> lazy;
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
    lazy.resize(1 + 4 * n);
  }
  void cleannode(int node, int from, int to) {
    if(lazy[node] == 1) {
      if(from < to) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
      }
      std::swap(aint[node].dp[0][1], aint[node].dp[1][0]);
      std::swap(aint[node].dp[0][0], aint[node].dp[1][1]);
      lazy[node] = 0;
    }
  }
  void computenode(int node, int from, int to) {
    if(from < to)
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
  }

  void build(int node, int from, int to, std::string &s) {
    if(from < to) {
      int mid = (from + to) / 2;
      build(node * 2, from, mid, s);
      build(node * 2 + 1, mid + 1, to, s);
      computenode(node, from, to);
    } else {
      if(s[from] == '4')
        aint[node].dp[0][0] = aint[node].dp[0][1] = aint[node].dp[1][0] = 1;
      else
        aint[node].dp[1][1] = aint[node].dp[0][1] = aint[node].dp[1][0] = 1;
    }
  }

  void update(int node, int from, int to, int x, int y) {
    cleannode(node, from, to);
    if(from == x && to == y) {
      lazy[node] ^= 1;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid));
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      computenode(node, from, to);
    }
  }
  int answer() {
    return aint[1].dp[0][1];
  }
};
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  std::string s;
  std::cin >> s;
  s = "#" + s;
  SegmentTree aint(n);
  aint.build(1, 1, n, s);

  for(int i = 1;i <= q; i++) {
    std::string op;
    std::cin >> op;
    if(op == "count")
      std::cout << aint.answer() << '\n';
    else {
      int x, y;
      std::cin >> x >> y;
      aint.update(1, 1, n, x, y);
    }
  }
  return 0;
}