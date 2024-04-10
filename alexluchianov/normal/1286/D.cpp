#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const modulo = 998244353;
int const nmax = 100000;

int x[1 + nmax], v[1 + nmax], p[1 + nmax];

struct Node{
  int mat[2][2];
  Node() {
    mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
  }
  Node operator * (Node oth) {
    Node sol;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int h = 0; h < 2; h++)
          sol.mat[i][j] = (sol.mat[i][j] + 1LL * mat[i][h] * oth.mat[h][j]) % modulo;
    return sol;
  }
  void _add(int x, int y, int val) {
    mat[x][y] = mat[x][y] + val;
  }
};

class SegmentTree{
private:
  std::vector<Node> aint;
public:
  SegmentTree(int n) {
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, int f0, int f1, int val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, f0, f1, val);
      else
        update(node * 2 + 1, mid + 1, to, x, f0, f1, val);
      aint[node] = aint[node * 2] * aint[node * 2 + 1];
    } else
      aint[node]._add(f0, f1, val);
  }

  int query() {
    int result = 0;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++) {
        if(i == 1) {
          result += 1LL * p[1] * aint[1].mat[i][j] % modulo;
          if(modulo <= result)
            result -= modulo;
        } else {
          result += 1LL * (100 - p[1]) * aint[1].mat[i][j] % modulo;
          if(modulo <= result)
            result -= modulo;
        }
      }
    return result;
  }
};

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

struct State{
  int a;
  int b;
  int x;
  int f0, f1;
  int p;
  int sign;
  
  //sign 0 mean unreachable
  
  void setsign() {
    sign = (0 < 1LL * a * b); 
  }
  
  int eval() {
    return 1LL * a * inverse(b) % modulo;
  }

  bool operator < (State const oth) const {
    if(sign == oth.sign)
      return 1LL * a * oth.b < 1LL * oth.a * b;
    else
      return oth.sign < sign;
  }
};


int main() {
  int n;
  std::cin >> n;
  if(n == 1) {
    std::cout << 0;
    return 0;
  }
  for(int i = 1;i <= n; i++) 
    std::cin >> x[i] >> v[i] >> p[i];
  std::vector<State> events;
  for(int i = 1; i < n; i++) {
    events.push_back({x[i + 1] - x[i], (v[i] - v[i + 1]), i, 1, 1, p[i + 1]});
    events.back().setsign();
    events.push_back({x[i + 1] - x[i], (v[i + 1] + v[i]), i, 1, 0, 100 - p[i + 1]});
    events.back().setsign();
    events.push_back({x[i + 1] - x[i], (v[i + 1] - v[i]), i, 0, 0, 100 - p[i + 1]});
    events.back().setsign();
    events.push_back({x[i + 1] - x[i], -(v[i + 1] + v[i]), i, 0, 1, p[i + 1]});
    events.back().setsign();
  }

  std::sort(events.begin(), events.end());
  std::vector<State> longevents;
  
  while(0 < events.size() && events.back().sign == 0) {
    longevents.push_back(events.back());
    events.pop_back();
  }
  
  SegmentTree aint(n);
  
  int result = 0;
  int global = inverse(lgpow(100, n));
  
  for(int i = 0; i < longevents.size(); i++) {
    aint.update(1, 1, n - 1, longevents[i].x, longevents[i].f0, longevents[i].f1, longevents[i].p);
  }
  
  if(0 < events.size()) {
    result = (1LL * -aint.query() * global) % modulo * events.back().eval() % modulo;
    if(result < 0)
      result += modulo;
  }

  for(int i = events.size() - 1; 0 <= i; i--) {
    aint.update(1, 1, n - 1, events[i].x, events[i].f0, events[i].f1, events[i].p);
    int last = 0;
    if(0 < i)
      last = events[i - 1].eval();
    result = (result + 1LL * aint.query() * global % modulo * (events[i].eval() - last)) % modulo;
    if(result < 0)
      result += modulo;
  }

  std::cout << result << '\n';
  return 0;
}