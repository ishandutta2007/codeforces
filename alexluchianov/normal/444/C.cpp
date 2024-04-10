#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

class SegmentTree{
private:
  vector<ll> aint;
  vector<ll> lazy;
public:
  SegmentTree(int n){
    aint.resize(4 * n);
    lazy.resize(4 * n);
  }
  void cleannode(int node, int from, int to){
    int mid = (from + to) / 2;
    if(from < to){
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    aint[node] += 1LL * lazy[node] * (to - from + 1);
    lazy[node] = 0;
  }
  void computenode(int node, int from, int to){
    if(from < to){
      aint[node] = aint[node * 2] + aint[node * 2 + 1];
    }
  }
  void update(int node, int from, int to, int x, int y, int val){
    if(y < x)
      return ;
    if(from == x && to == y){
      lazy[node] += val;
      cleannode(node, from, to);
    } else {
      int mid = (from + to) / 2;
      cleannode(node * 2, from, mid);
      cleannode(node * 2 + 1, mid + 1, to);

      if(x <= mid)
        update(node * 2, from, mid, x, MIN(y, mid), val);
      if(mid + 1 <= y)
        update(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y, val);
      computenode(node, from, to);
    }
  }

  ll query(int node, int from, int to, int x, int y){
    cleannode(node, from, to);
    if(from == x && to == y){
      return aint[node];
    } else {
      int mid = (from + to) / 2;
      ll result = 0;
      if(x <= mid)
        result += query(node * 2, from, mid, x, MIN(mid, y));
      if(mid + 1 <= y)
        result += query(node * 2 + 1, mid + 1, to, MAX(mid + 1, x), y);
      return result;
    }
  }
};

map<int,int> mp;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  mp[n + 1] = n + 1;
  for(int i = 1;i <= n; i++)
    mp[i] = i;
  SegmentTree aint(n);
  for(int i = 1;i <= m; i++){
    int type;
    cin >> type;
    if(type == 1){
      int l, r, x;
      cin >> l >> r >> x;
      map<int,int>::iterator it;
      it = mp.upper_bound(l);
      it--;

      vector<pair<int,int>> candidates;
      while(it->first <= r){
        candidates.push_back(*it);
        mp.erase(it++);
      }
      candidates.push_back({n + 1, 1});

      mp[l] = x;
      mp.insert(candidates[0]);
      mp.insert({l, x});
      for(int i = 0;i < candidates.size() - 1; i++)
        aint.update(1, 1, n, MAX(l, candidates[i].first), MIN(r, candidates[i + 1].first - 1), fabs(x - candidates[i].second));

      candidates.pop_back();

      if(mp.find(r + 1) == mp.end())
        mp.insert({r + 1, candidates.back().second});
    } else {
      int l, r;
      cin >> l >> r;
      cout << aint.query(1, 1, n, l, r) << '\n';
    }
  }
  return 0;
}