#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;

int const nmax = 100000;
int const modulo = 1000000007;
int v[5 + nmax];

void normalize(int n) {
  std::vector<int> aux;
  for(int i = 1;i <= n; i++)
    aux.push_back(v[i]);
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  std::map<int,int> mp;
  for(int i = 0; i < aux.size(); i++) 
    mp[aux[i]] = 1 + i;
  for(int i = 1;i <= n; i++)
    v[i] = mp[v[i]];
}

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
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }
  int query(int pos) {
    int result = 0;
    for(int x = pos;0 < x; x = (x &(x - 1)))
      result += aib[x];
    return result;
  }
};

class SegmentTree{
private:
  struct Node{
    int result;
    int sum;
    int left;
    int left2;
    int right;
    int right2;
    Node(int val_ = 0, int _left = 0, int _right = 0) {
      result = 0;
      sum = val_;
      left = _left;
      right = _right;
      left2 = 0;
      right2 = 0;
    }
    Node operator + (Node const oth) {
      Node answer;
      answer.result = (result + oth.result + 1LL * left * oth.right2 + 1LL * left2 * oth.right) % modulo;
      answer.sum = sum + oth.sum;
      answer.left = (left + oth.left);
      answer.right = (right + oth.right);
      answer.left2 = (left2 + oth.left2 + 1LL * left * oth.sum) % modulo;
      answer.right2 = (right2 + oth.right2 + 1LL * sum * oth.right) % modulo;
      return answer;
    }
  };
  std::vector<Node> aint;
public:
  SegmentTree(int n = 0) {
    aint.resize(2 + 4 * n);
  }
  void update(int node, int from, int to, int x, int val, int _left, int _right) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val, _left, _right);
      else
        update(node * 2 + 1, mid + 1, to,x , val, _left, _right);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
      
    } else
      aint[node] = {val, _left, _right};
  }
  int query() {
    return aint[1].result;
  }
};

int leftSup[5 + nmax], rightSup[5 + nmax];
int frec[5 + nmax], pos[5 + nmax];
SegmentTree aint[5 + nmax];

void computeSup(int n) {
  FenwickTree aib(n);
  for(int i = 1; i <= n; i++) {
    leftSup[i] = aib.query(v[i]);
    aib.update(v[i], 1);
  }
  aib = FenwickTree(n);
  for(int i = n; 1 <= i; i--) {
    rightSup[i] = aib.query(v[i]);
    aib.update(v[i], 1);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  normalize(n);
  computeSup(n);
  for(int i = 1;i <= n; i++) {
    frec[v[i]]++;
    pos[i] = frec[v[i]];
  }
  for(int i = 1;i <= n; i++)
    aint[i] = SegmentTree(frec[i]);
  

  for(int i = 1;i <= n; i++) 
    aint[v[i]].update(1, 1, frec[v[i]], pos[i], 1, leftSup[i], rightSup[i]);
  int base = 0;
  for(int i = 1;i <= n; i++) {
    base += aint[i].query();
    if(modulo <= base)
      base -= modulo;
  }
  int q;
  std::cin >> q;

  for(int i = 1; i <= q; i++) {
    int op, x;
    std::cin >> op >> x;
    base -= aint[v[x]].query();
    if(base < 0)
      base += modulo;
    if(op == 2)
      aint[v[x]].update(1, 1, frec[v[x]], pos[x], 1, leftSup[x], rightSup[x]);
    else
      aint[v[x]].update(1, 1, frec[v[x]], pos[x], 0, 0, 0);
    base += aint[v[x]].query();
    if(modulo <= base)
      base -= modulo;
    std::cout << base << '\n';
  }
  return 0;
}