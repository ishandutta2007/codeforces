#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 300000;
int const lgmax = 16;
int v[1 + nmax];

struct Interval{
  int x;
  int y;
  Interval operator + (Interval const &a) const{
    return {MIN(x, a.x), MAX(y, a.y)};
  }
};

class SegmentTree{
private:
  vector<Interval> aint;
public:
  SegmentTree(int n = 0){
    aint.resize(1 + 4 * n);
  }
  void update(int node, int from, int to, int x, Interval val){
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    } else
      aint[node] = val;
  }

  Interval query(int node, int from, int to, int x, int y){
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y);
    }
  }
};
SegmentTree far[1 + lgmax];
int n;

Interval raisebypower(Interval init, int h){
  return far[h].query(1, 1, n, init.x, init.y);
}

int getsz(Interval a) {
  return a.y - a.x + 1;
}

int solve(int start, int target){
  Interval init = {start, start};
  if(target == 1)
    return 0;

  int x = 0;
  for(int h = lgmax - 1; 0 <= h; h--){
    Interval newinterval = raisebypower(init, h);
    if(getsz(newinterval) < target){
      init = newinterval;
      x += (1 << h);
    }
  }
  return x + 1;
}

int main()
{
  int n_;
  cin >> n_;
  n = n_ * 3;

  for(int i = 1;i <= n_; i++)
    cin >> v[i];
  for(int i = 1;i <= n_; i++)
    v[i + 2 * n_] = v[i + n_] = v[i];

  for(int i = 0; i < lgmax; i++)
    far[i] = SegmentTree(n);

  for(int i = 1;i <= n; i++)
    far[0].update(1, 1, n, i, {MAX(1, i - v[i]), MIN(n, i + v[i])} );

  for(int h = 1; h < lgmax; h++)
    for(int i = 1;i <= n; i++) {
      Interval init = far[h - 1].query(1, 1, n, i, i);
      int x = init.x, y = init.y;
      Interval result = far[h - 1].query(1, 1, n, x, y);
      far[h].update(1, 1, n, i, result);
    }

  for(int i = n_ + 1; i <= n_ * 2; i++)
    cout << solve(i, n_) << " ";
  return 0;
}