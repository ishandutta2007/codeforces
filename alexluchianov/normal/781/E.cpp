#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cassert>
#include <set>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 100000;
int const modulo = 1000000007;

map<int,int> code;

class SegmentTree{
public:
  vector<set<int>> aint;
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
  }

  void build(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      build(node * 2, from, mid);
      build(node * 2 + 1, mid + 1, to);
    }
    aint[node].insert(0);
  }

  void update(int node, int from, int to, int x, int y, int val){
    if(from == x && to == y) {
      if(0 < val)
        aint[node].insert(val);
      else
        aint[node].erase(-val);
    } else {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
    }
  }

  int query(int node, int from, int to, int x){
    if(from < to){
      int mid = (from + to) / 2;
      set<int>::iterator it;
      it = aint[node].end();
      it--;
      int result = *it;
      if(x <= mid)
        return max(result, query(node * 2, from, mid, x));
      else
        return max(result, query(node * 2 + 1, mid + 1, to, x));
    } else {
      set<int>::iterator it;
      it = aint[node].end();
      it--;
      return *it;
    }
  }
};

struct Block{
  int h;
  int l;
  int r;
  int s;
  bool operator < (Block const &a) const{
    return h < a.h;
  }
} v[1 + nmax];
int dp[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int lim, n, q;
  cin >> lim >> n >> q;
  SegmentTree aint(n);
  aint.build(1, 1, n);
  code[0] = 0;
  dp[0] = 1;
  for(int i = 1;i <= q; i++){
    cin >> v[i].h >> v[i].l >> v[i].r >> v[i].s;
  }
  sort(v + 1, v + q + 1);
  multiset<Block> pq;

  for(int i = 1;i <= q; i++){
    code[v[i].h] = i;
    while(0 < pq.size() && pq.begin()->h < v[i].h){
      Block pqtop = *pq.begin();
      pq.erase(pq.begin());
      aint.update(1, 1, n, pqtop.l, pqtop.r, -(pqtop.h - pqtop.s));
    }
    int x = v[i].l - 1;
    int y = v[i].r + 1;
    if(x == 0)
      x = y;
    if(y == n + 1)
      y = x;
    dp[i] = dp[code[aint.query(1, 1, n, x)]] + dp[code[aint.query(1, 1, n, y)]];
    if(modulo <= dp[i])
      dp[i] -= modulo;

    aint.update(1, 1, n, v[i].l, v[i].r, v[i].h);
    pq.insert(Block{v[i].h + v[i].s, v[i].l, v[i].r, v[i].s});
  }

  int result = 0;
  for(int i = 1;i <= n; i++){
    while(0 < pq.size() && pq.begin()->h < lim + 1){
      Block pqtop = *pq.begin();
      pq.erase(pq.begin());
      aint.update(1, 1, n, pqtop.l, pqtop.r, -(pqtop.h - pqtop.s));
    }
    result += dp[code[aint.query(1, 1, n, i)]];
    if(modulo <= result)
      result -= modulo;
  }
  cout << result;
  return 0;
}