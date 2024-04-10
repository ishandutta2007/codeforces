#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 200000;
int const modulo = 998244353;

class SegmentTree{
private:
  vector<int> aint;
  vector<int> lazy1;
  vector<int> lazy2;
public:
  SegmentTree(int n){
    aint.resize(1 + 4 * n);
    lazy1.resize(1 + 4 * n);
    for(int i = 1;i <= 4 * n; i++)
      lazy1[i] = 1;
    lazy2.resize(1 + 4 * n);
  }

  void cleannode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      lazy1[node * 2] = (1LL * lazy1[node * 2] * lazy1[node]) % modulo;
      lazy2[node * 2] = (1LL * lazy2[node * 2] * lazy1[node] + lazy2[node]) % modulo;

      lazy1[node * 2 + 1] = (1LL * lazy1[node * 2 + 1] * lazy1[node]) % modulo;
      lazy2[node * 2 + 1] = (1LL * lazy2[node * 2 + 1] * lazy1[node] + lazy2[node]) % modulo;
    }
    aint[node] = (1LL * aint[node] * lazy1[node] + 1LL * (to - from + 1) * lazy2[node]) % modulo;
    lazy1[node] = 1;
    lazy2[node] = 0;
  }

  void computenode(int node, int from, int to){
    if(from < to){
      int mid = (from + to) / 2;
      aint[node] = (aint[node * 2] + aint[node * 2 + 1]) % modulo;
    }
  }

  void update(int node, int from, int to, int x, int y, int val){
    if(y < x)
      return ;

    cleannode(node, from, to);
    if(from == x && to == y){
      lazy1[node] = val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  void update2(int node, int from, int to, int x, int y, int val){
    if(y < x)
      return ;

    cleannode(node, from, to);
    if(from == x && to == y){
      lazy2[node] = val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);
      if(x <= mid)
        update2(node * 2, from, mid, x, MIN(mid, y), val);
      if(mid + 1 <= y)
        update2(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  int query(int node, int from, int to, int x, int y){
    if(y < x)
      return 0;

    cleannode(node, from, to);
    if(from == x && to == y)
      return aint[node];
    else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return query(node * 2 + 1, mid + 1, to, x, y);
      else
        return (query(node * 2, from, mid, x, mid) + query(node * 2 + 1, mid + 1, to, mid + 1, y)) % modulo;
    }
  }
};

set<pair<int,int>> myset[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  SegmentTree aint(n);
  for(int i = 1;i <= m; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x, y, val;
      cin >> x >> y >> val;
      set<pair<int,int>>::iterator it = myset[val].lower_bound({x, 0});
      if(it != myset[val].begin())
        it--;
      vector<pair<int,int>> queries;

      while(it != myset[val].end() && it->first <= y){
        queries.push_back(*it);
        myset[val].erase(it++);
      }

      int last = 0, newx = x, newy = y;

      for(int i = 0; i < queries.size(); i++){
        aint.update2(1, 1, n, MAX(x, last + 1), queries[i].first - 1, 1);
        if(x <= queries[i].second)
          newx = MIN(newx, queries[i].first);
        else
          myset[val].insert(queries[i]);

        if(queries[i].first <= y)
          newy = MAX(newy, queries[i].second);
        else
          myset[val].insert(queries[i]);

        aint.update(1, 1, n, MAX(x, queries[i].first), MIN(y, queries[i].second), 2);
        last = queries[i].second;
      }

      aint.update2(1, 1, n, MAX(x, last + 1), y, 1);

      myset[val].insert({newx, newy});
    } else {
      int x, y;
      cin >> x >> y;
      cout << aint.query(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}
/*
4 6
1 2 2 1
1 4 4 1
1 1 4 2
2 1 4

*/