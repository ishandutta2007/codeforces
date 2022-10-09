#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int const nmax = 100000;
int const inf = 1000000000;
int const lgmax = 20;
int v[1 + nmax];


struct Query{
  int op;
  int x;
  int y;
  int cost;
  bool operator < (Query const &a) const {
    if(x != a.x)
      return x < a.x;
    else
      return op > a.op;
  }
};
class SegmentTree{
private:
  vector<int> aint;
  int n;
  int mode;
public:
  SegmentTree(int n_, int mode_){
    n = n_;
    mode = mode_;
    aint.resize(1 + 4 * n);
    if(mode == 1)
      for(int i = 1;i <= 4 * n; i++)
        aint[i] = inf + 1;
    else
      for(int i = 1;i <= 4 * n; i++)
        aint[i] = -1;
  }
  int join(int a, int b){
    if(mode == 2)
      return max(a, b);
    else
      return min(a, b);
  }
  void update(int node, int from, int to, int x, int val){
    if(from < to){
      int mid = (from + to) / 2;
      if(x <= mid)
        update(node * 2, from, mid, x, val);
      else
        update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }

  ///find first element lower than target
  int _search1(int node, int from, int to, int x, int target){
    if(target < aint[node])
      return 0;

    if(from < to){
      int mid = (from + to) / 2, result1;
      if(x < mid) {
        result1 = _search1(node * 2, from, mid, x, target);
        if(result1 == 0)
          return _search1(node * 2 + 1, mid + 1, to, x, target);
        else
          return result1;
      } else
        return _search1(node * 2 + 1, mid + 1, to, x, target);
    } else
      return from;
  }

  int _search2(int node, int from, int to, int x, int target){
    if(aint[node] < target)
      return 0;

    if(from < to){
      int mid = (from + to) / 2, result1;
      if(x < mid) {
        result1 = _search2(node * 2, from, mid, x, target);
        if(result1 == 0)
          return _search2(node * 2 + 1, mid + 1, to, x, target);
        else
          return result1;
      } else
        return _search2(node * 2 + 1, mid + 1, to, x, target);
    } else
      return from;
  }
};

struct FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n_){
    n = n_;
    aib.resize(1 + n);
    for(int i = 1;i <= n; i++)
      aib[i] = inf;
  }
  void update(int pos, int val){
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] = min(aib[x], val);
  }
  int query(int pos){
    int result = aib[pos];
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result = min(result, aib[x]);
    return result;
  }
};
int sol[1 + 3 * nmax];

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  vector<Query> queries;
  SegmentTree aint(n, 1);
  vector<pair<int,int>> lis;
  for(int i = 1;i <= n; i++)
    lis.push_back({v[i], i});
  sort(lis.begin(), lis.end());

  for(int i = lis.size() - 1; 0 <= i; i--){
    int start = lis[i].second;
    int target = inf;
    while(true){
      int pos = aint._search1(1, 1, n, start, target);
      if(pos == 0 || pos == start)
        break;
      queries.push_back({0, start, pos, fabs(v[start] - v[pos])});
      target = (v[start] + v[pos]) / 2;

      if(target == v[pos])
        break;
    }
    aint.update(1, 1, n, start, v[start]);
  }

  aint = SegmentTree(n, 2);
  for(int i = 0; i < lis.size(); i++){
    int start = lis[i].second;
    int target = 0;
    while(true){
      int pos = aint._search2(1, 1, n, start, target);
      if(pos == 0 || pos == start)
        break;
      queries.push_back({0, start, pos, fabs(v[start] - v[pos])});
      target = (v[start] + v[pos]) / 2;
      if(target == v[pos])
        break;
    }
    aint.update(1, 1, n, start, v[start]);
  }


  int q;
  cin >> q;
  for(int i = 1; i <= q; i++){
    int x, y;
    cin >> x >> y;
    queries.push_back({1, x, y, i});
  }
  sort(queries.begin(), queries.end());
  reverse(queries.begin(), queries.end());

  FenwickTree aib(1 + n);
  for(int i = 0; i < queries.size(); i++){
    Query curr = queries[i];
    if(curr.op == 0)
      aib.update(curr.y, curr.cost);
    else
      sol[curr.cost] = aib.query(curr.y);
  }
  for(int i = 1;i <= q; i++)
    cout << sol[i] << '\n';
  return 0;
}
/*
4
10 1 20 11
3
1 2
1 3
1 4


7
20 1 8 6 4 3 1
6
1 2
1 3
1 4
1 5
1 6
1 7
*/